#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

#include "SubApart.h"
#include "Fragment.h"
#include "Translate.h"

std::ostream& operator<<(std::ostream& os, const SubLevel& sl)
{
  os << static_cast<int>(sl.mLevel)
     << "."
     << static_cast<int>(sl.mSubLevel);
  return os;
}

SubLevel SubApart(Assembly assm, const OffsetTable& ot, const ReflectTable& rt)
{
  struct Node{
    bool operator==(const Fragment& f) const {return frag == f;}

    Fragment frag;
    Level level;
  };

  Partition set = Partition::All();

  std::vector<Node> nodes;
  Fragment root;
  nodes.push_back({root, 0});

  SubLevel ret{0, 0};

  static std::array<Translate, 6> directions{{
    {2, 0, 0}, {0, 2, 0}, {0, 0, 2}, {-2, 0, 0}, {0, -2, 0}, {0, 0, -2}}};

  for (unsigned i{0}; i < nodes.size(); ++i){
    if (ret.mLevel && nodes[i].level + 1u > ret.mLevel) return ret;

    for (const Translate dir : directions){
      for (Partition move{1u}; !move.IsIn(5); ++move){

        if (!move.IsSubset(set)) continue;
        Partition stat = move.Complement(set);
        Fragment test{nodes[i].frag};

        do{
          test.Shift(move, dir);
          if (!test.CheckFit(move, stat, assm, ot)) break;

          if (test.CheckFree(move, stat, dir)){
            Level sub_m{Apart(assm, ot, rt, move, test)};
            if (!sub_m) return {0, 0};

            Level sub_s{Apart(assm, ot, rt, stat, test)};
            if (!sub_s) return {0, 0};

            Level level = static_cast<Level>(nodes[i].level + 1u);
            Level sublevel{0};

            if (move.IsSingle()) sublevel = sub_s;
            else if (stat.IsSingle()) sublevel = sub_m;
            else sublevel = std::min(sub_s, sub_m);

            if (!ret.mSubLevel || sublevel < ret.mSubLevel) {
              ret = SubLevel({level, sublevel});
            }

            break;
          }

          if (std::find(nodes.begin(), nodes.end(), test) == nodes.end()){
            nodes.push_back({test, static_cast<Level>(nodes[i].level + 1u)});
          }

        } while (true);
      }
    }
  }

  return {0, 0};
}

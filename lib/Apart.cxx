#include <algorithm>
#include <array>
#include <cassert>
#include <vector>

#include "Apart.h"
#include "Fragment.h"
#include "Translate.h"

Level Apart(Assembly assm, const OffsetTable& ot, const ReflectTable& rt,
            Partition set, Fragment root)
{
  struct Node{
    bool operator==(const Fragment& f) const {return frag == f;}

    Fragment frag;
    Level level;
  };

  if (!set.ThreeAxes()) return 1;

  std::vector<Node> nodes;
  nodes.push_back({root, 0});

  static std::array<Translate, 6> directions{{
    {2, 0, 0}, {0, 2, 0}, {0, 0, 2}, {-2, 0, 0}, {0, -2, 0}, {0, 0, -2}}};

  for (unsigned i{0}; i < nodes.size(); ++i){
    for (const Translate dir : directions){
      for (Partition move{1u}; !move.IsIn(set.First()); ++move){

        if (!move.IsSubset(set)) continue;
        Partition stat = move.Complement(set);

        Fragment test{nodes[i].frag};
        do{
          test.Shift(move, dir);
          if (!test.CheckFit(move, stat, assm, ot)) break;

          if (test.CheckFree(move, stat, dir)){
            if (!Apart(assm, ot, rt, move)) return 0;
            if (!Apart(assm, ot, rt, stat)) return 0;
            return static_cast<Level>(nodes[i].level + 1u);
          }

          if (std::find(nodes.begin(), nodes.end(), test) == nodes.end()){
            nodes.push_back({test,
                 static_cast<Level>(nodes[i].level + 1u)});
          }
        } while (true);
      }
    }
  }

  return 0;
}

#include <vector>
#include <algorithm>
#include <array>

#include "Apart.h"
#include "Fragment.h"
#include "Translate.h"
#include "Partition.h"

unsigned char Apart(std::array<Piece, 6> pieces)
{
  struct Node{
    bool operator==(const Fragment& f) const {return frag == f;}

    Fragment frag;
    unsigned char level;
  };

  std::vector<Node> nodes;
  Fragment root;
  nodes.push_back({root, 0});

  static std::array<Translate, 6> directions{{
    {2, 0, 0}, {0, 2, 0}, {0, 0, 2}, {-2, 0, 0}, {0, -2, 0}, {0, 0, -2}}};

  for (unsigned i{0}; i < nodes.size(); ++i){
    for (const Translate dir : directions){
      for (Partition part{1}; part.IsProper(); ++part){
        Fragment test{nodes[i].frag};
        do{
          test.Shift(part, dir);
          if (!test.CheckFit(part, pieces)) break;

          if (test.CheckFree(part, dir)){
            return static_cast<unsigned char>(nodes[i].level + 1u);
          }

          if (std::find(nodes.begin(), nodes.end(), test) == nodes.end()){
            nodes.push_back({test,
                 static_cast<unsigned char>(nodes[i].level + 1u)});
          }
        } while (true);
      }
    }
  }

  return 0;
}

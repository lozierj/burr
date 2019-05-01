#include <iostream>
#include <fstream>
#include <algorithm>

#include "../lib/Generator.h"
#include "../lib/Notchables.h"

#include "../lib/Translate.h"
#include "../lib/TestFit.h"

int main()
{
  Generator g{Notchables()};
  g.Generate();

  /*
  const std::vector<Piece> pieces{Notchables()};
  const EquivTable et{pieces};

  std::ifstream s("data/ip2.tsv");
  s >> std::hex;

  for(int line{1}; line <= 164; ++line){
   Assembly a;

    for (unsigned i{0}; i < 6; ++i){
      unsigned short n;
      s >> n;
      auto it = std::find(pieces.begin(), pieces.end(), Piece::Notchable(n));
      if (it == pieces.end()) throw std::logic_error("piece not in set");
      a[i] = it - pieces.begin();
    }

    a.ToSetForm(et);

    std::cout << a << "   L5 ";
    for (Position i{0}; i < 6; ++i){
      std::cout << "  " << pieces[a[i]];
    }

    std::cout << std::endl;
  }
  */
}

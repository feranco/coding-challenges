//#include "hanoiTowersParams.h"
#include "hanoiTowersReturn.h"
#include <iostream>
#include <vector>
//#include <list>
#include <stdexcept>

int main () {
  Move m{5, 0, 1, 2};
  auto moves = hanoiReturn(m);

  for (const auto& move : moves) {
    std::cout << "Disk " << move.id << " from " << move.src << " to " << move.dst << "\n";
  }
}

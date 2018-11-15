#include <vector>
#include <iostream>
#include "move.h"

std::vector<Move> hanoi (Move move) {

  std::vector<Move> moves;
  
  if (move.id == 0) return moves;

  auto srcToAux = hanoi({move.id-1, move.src, move.aux, move.dst});
  moves.insert(moves.end(), srcToAux.begin(), srcToAux.end()); 
  moves.push_back(move);//move(id, src, dst);
  auto auxToDst = hanoi({move.id-1, move.aux, move.dst, move.src});
  moves.insert(moves.end(), auxToDst.begin(), auxToDst.end());

  return moves;
}

std::vector<Move> hanoiReturn (Move move) {
  return hanoi(move);
}

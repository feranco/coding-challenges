#include <vector>
#include <iostream>
#include "move.h"

void hanoi (Move move, std::vector<Move>& moves) {
  
  if (move.id == 0) return;

  hanoi({move.id-1, move.src, move.aux, move.dst}, moves);
  moves.push_back(move);
  hanoi({move.id-1, move.aux, move.dst, move.src}, moves);
}

std::vector<Move> hanoiParams (Move move) {
  std::vector<Move> moves;
  hanoi(move, moves);
  return moves;
}



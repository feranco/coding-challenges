//algorithm generating all the possible placements of 8 queens in a 8x8 chessboard
//1) since two or more queens must be in different rows, a placement is coded
//with a vector of size n: each element represent the position of the queen in the corresponding row
//the approach is similar to the coding challenge queens_placements with the only difference that
//the placement is executed in reverse order; moreover a fixed size array is used instead of a vector

#include <array>
#include <iostream>

using std::array;
using std::cout;

const int chess_size = 8;

void printChess (const array<int,chess_size>& chess) {
    for (auto queen : chess) cout << queen << " ";
    cout << std::endl;
}

bool checkPosition (array<int,chess_size> chess, int row, int pos) {

  for (int i = row+1; i < chess_size; ++i) {
    if (chess[i] == pos) return false;
  }
  
  for (int i = row+1, invalid = pos-1; (i < chess_size && invalid >= 0); ++i, --invalid) {
    if (chess[i] == invalid) return false;
  }

  for (int i = row+1, invalid = pos+1; (i < chess_size && invalid <= chess_size); ++i, ++invalid) {
    if (chess[i] == invalid) return false;
  }
  return true;
}

void arrangeQueen (array<int,chess_size> chess, int row) {
  if (row < 0) {
    printChess(chess);
    return;
  }

  for (int i = 0; i < chess_size; ++i) {
    if (checkPosition(chess, row, i)) {
      chess[row] = i;
      arrangeQueen(chess, row - 1);
    }
  }
}

int main (void) {
  array<int,chess_size> chess;
  for (auto queen : chess) queen = -1;
  arrangeQueen(chess, chess_size-1);
}

//algorithm to solve sudoku problem

#include <array>
#include <iostream>
#include <vector>

using namespace std;
const int size = 9;

void printSudoku (const array<array<int,size>,size>& sudoku) {
  for (const auto& row : sudoku) {
    for (const auto& col : row) {
      cout << col << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void buildSudoku (array<array<int,size>,size>* sudoku_ptr) {
  array<array<int,size>,size>& sudoku = *sudoku_ptr;
  sudoku[0][0] = 5;
  sudoku[0][1] = 3;
  sudoku[0][4] = 7;
  sudoku[1][0] = 6;
  sudoku[1][3] = 1;
  sudoku[1][4] = 9;
  sudoku[1][5] = 5;
  sudoku[2][1] = 9;
  sudoku[2][2] = 8;
  sudoku[2][7] = 6;
  sudoku[3][0] = 8;
  sudoku[3][4] = 6;
  sudoku[3][8] = 3;
  sudoku[4][0] = 4;
  sudoku[4][3] = 8;
  sudoku[4][5] = 3;
  sudoku[4][8] = 1;
  sudoku[5][0] = 7;
  sudoku[5][4] = 2;
  sudoku[5][8] = 6;
  sudoku[6][1] = 6;
  sudoku[6][6] = 2;
  sudoku[6][7] = 8;
  sudoku[7][3] = 4;
  sudoku[7][4] = 1;
  sudoku[7][5] = 9;
  sudoku[7][8] = 5;
   sudoku[8][4] = 8;
  sudoku[8][7] = 7;
  sudoku[8][8] = 9;
}

vector<int> buildPossibleValues (const array<array<int,size>,size>& sudoku, int row, int col) {
  vector<int> result;
  for (int i = 1; i <=size; ++i) {
    bool is_possible = true;
    //check row
    for (int j = 0; j < size && is_possible; ++j) {
      if (sudoku[row][j] == i)  is_possible = false;
    }

    //check col
    for (int j = 0; j < size && is_possible; ++j) {
      if (sudoku[j][col] == i)  is_possible = false;
    }
    
    //check region
    int row_start, row_end;
    if (row <= 2) {
      row_start = 0;
      row_end = 2;
    }
    else if (row <=5) {
      row_start = 3;
      row_end = 5;
    }
    else {
      row_start = 6;
      row_end = 8;
    }

    int col_start, col_end;
    if (col <= 2) {
      col_start = 0;
      col_end = 2;
    }
    else if (col <=5) {
      col_start = 3;
      col_end = 5;
    }
    else {
      col_start = 6;
      col_end = 8;
    }

    for (int j = row_start; j <= row_end; ++j) {
       for (int k = col_start; k <= col_end; ++k) {
	 if (sudoku[j][k] == i)  is_possible = false;
       }	 
    }
    if (is_possible) result.emplace_back(i);
  }
  return result;
}

void makeMove (int* row, int* col) {
  if (*col == (size-1)) {
    *col = 0;
    *row = (*row)+1;
  }
  else {
    *col = (*col)+1;
  }
}

void unmakeMove (int* row, int* col) {
  //if (*col == 0 && *row == 0) return;
  if (*col == 0 && *row != 0) {
    *col = size-1;
    *row = (*row)-1;
  }
  else if (col != 0){
    *col = (*col)-1;
  }
}

void solveSudoku (array<array<int,size>,size>* sudoku_ptr, bool* finished, int row, int col) {
  array<array<int,size>,size>& sudoku = *sudoku_ptr;
  cout << row << " " << col << "\n";
  if (row >= size || col >= size) {
    *finished = true;
    return;
  }
  else {
    if (sudoku[row][col] == 0) {
      auto candidateValues = buildPossibleValues (sudoku, row, col);
      for (auto candidate : candidateValues) {
	sudoku[row][col] = candidate;
	makeMove(&row, &col);
	solveSudoku(sudoku_ptr, finished, row, col);
	if(*finished) return;
	unmakeMove(&row, &col);
	sudoku[row][col] = 0;
      }
    }
    else {
      	makeMove(&row, &col);
	solveSudoku(sudoku_ptr, finished, row, col);
	if(*finished) return;
	unmakeMove(&row, &col);
    }
  }
}

void solveSudoku (array<array<int,size>,size>* sudoku_ptr) {
  bool finished = false;
  solveSudoku(sudoku_ptr, &finished, 0, 0);
}

int main (void) {
  array<array<int,size>,size> sudoku{};
  buildSudoku(&sudoku);
  printSudoku(sudoku);
  solveSudoku(&sudoku);
  printSudoku(sudoku);
}

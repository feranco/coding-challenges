#include <iostream>
#include <vector>

using std::cout;
using std::vector;

template <typename T>
bool searchSortedMatrix (const vector<vector<T>>& matrix, T target) {
  size_t rows = matrix.size(), cols = matrix[0].size();
  if (target < matrix[0][0] || target > matrix[rows-1][cols-1]) return false;
  size_t r = 0, c = cols-1;
  while (r < rows && c < cols) {
    if (target == matrix[r][c]) return true;
    if (target < matrix[r][c]) c--;
    else r++;
  }
  return false;
}

int main (void) {
  vector<vector<int>> matrix{{-1,2,4,4,6},{1,5,5,9,21},{3,6,6,9,22},{3,6,8,10,24},
			     {6,8,9,12,25},{11,13,14,16,40}};

  cout << searchSortedMatrix(matrix, 15);
}

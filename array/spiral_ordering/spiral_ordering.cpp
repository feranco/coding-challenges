//algorithm to visit the elements of a 2D matrix in spiral order
//O(n) time, O(1) space
#include <vector>
#include <iostream>

using namespace std;

void spiralOrdering(const vector<vector<int>>& matrix, int start, int end, vector<int>* ordering) {
  if (end < start) return;

  //visit up row
  for (int y = start; y <= end; ++y) ordering->emplace_back(matrix[start][y]);
  //visit right col
  for (int x = start+1; x < end; ++x) ordering->emplace_back(matrix[x][end]);
  //visit down row
  for (int y = end; y > start; --y) ordering->emplace_back(matrix[end][y]);
  //visit left col
  for (int x = end; x > start; --x) ordering->emplace_back(matrix[x][start]);

  spiralOrdering(matrix, start + 1, end - 1, ordering);
}


vector<int> spiralOrdering(const vector<vector<int>>& matrix) {
  vector<int> ordering;
  spiralOrdering(matrix, 0, matrix.size() - 1, &ordering);
  return ordering;
}

int main(void) {
  vector<vector<int>> a{ { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };
  auto spiral = spiralOrdering(a);
  for (int x : spiral) cout << x << " ";
}

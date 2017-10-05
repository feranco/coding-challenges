//algorithm to find enclosed regions in a 2d matrix
//i.e. O surrounded by all X
//O(m*n)

#include <vector>	
#include <queue>
#include <iostream>
#include <utility>

using  namespace std;

void findEnclosedRegions(vector<vector<char>>* A_ptr) {
  vector<vector<char>> A = * A_ptr;
  if(A.empty()) return;
  
  int n_rows = A.size(), n_cols = A[0].size();
  queue<pair<int, int> > q;

  //insert O in the first/last column
  for (int i = 0; i < n_rows; ++i) {
    if (A[i][0] == 'O') q.emplace(make_pair(i, 0));
    if (A[i][n_cols - 1] == 'O') q.emplace(make_pair(i, n_cols - 1));
  }
  //insert O in the first/last row
  for (int i = 0; i < n_cols; ++i) {
    if (A[0][i] == 'O') q.emplace(make_pair(0, i));
    if (A[n_rows - 1][i] == 'O') q.emplace(make_pair(n_rows - 1, i));
  }

  //BFS inserted O marking all visited cells with B
  while (!q.empty()) {
    const auto& current = q.front();
    q.pop();
    int x = current.first, y = current.second;
    A[x][y] = 'B';
    vector<pair<int, int>> next{ {x - 1,y},{x,y + 1},{x + 1,y},{x,y - 1}};
    for (const auto& point : next) {
      int next_x = point.first, next_y = point.second;
      if (next_x >= 0 && next_x < n_rows && next_y >= 0 && next_y < n_cols) {
	if (A[next_x][next_y] == 'O') q.emplace(make_pair(next_x, next_y));
      }
    }
  }

  //replace all B with O and all others with X
  for (int i = 0; i < n_rows; ++i) {
    for (int j = 0; j < n_cols; ++j) {
      if (A[i][j] != 'B') A[i][j] = 'X';
      else A[i][j] = 'O';
    }
  }

}

int main(void) {
  vector<vector<char>> input{ {'X','X','X','X'},{ 'X','O','O','X' },{ 'X','X','O','X' },{ 'X','O','X','X' } };
  findEnclosedRegions(&input);
}

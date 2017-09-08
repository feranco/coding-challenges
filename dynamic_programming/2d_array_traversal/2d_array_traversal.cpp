//algorithm countin the number of possible traversal of a 2d array 
//of size n*m from (0,0) to (n-1,m-1)

#include <vector>
#include <iostream>

using namespace std;

//Solution 1:
//recursion naive
//O(2(n*m)
struct Coordinate {
  int x;
  int y;
  bool isValid(const vector<vector<int>>& matrix) {
    return (x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size());
  }
  bool operator==(const Coordinate& rhs) {
    return (x == rhs.x && y == rhs.y);
  }
};

//Solution 1:
//recursion naive
//O(2^n)
int call = 0;
int countTraversal (const vector<vector<int>>& matrix, Coordinate curr) {
  const Coordinate start{0,0};
  //cout << ++call << endl;
  if (!curr.isValid(matrix)) return 0;
  if (curr == start) return 1;
  return (countTraversal(matrix, {curr.x-1,curr.y}) + countTraversal(matrix, {curr.x, curr.y-1}));
}

/*
int call = 0;
void countTraversal (const vector<vector<int>>& matrix, int* cnt, Coordinate curr, Coordinate end) {
   cout << ++call << endl;
  if (!curr.isValid(matrix) || !end.isValid(matrix)) return;
 
  if (curr == end) {
    (*cnt)++;
    return;
  }
  countTraversal(matrix, cnt, {curr.x,curr.y+1}, end);
  countTraversal(matrix, cnt, {curr.x+1, curr.y}, end);
}
*/

//Solution 2:
//dp with cache (top down)
//O(n*m)
int countTraversalCache (const vector<vector<int>>& matrix, Coordinate curr, vector<vector<int>>* cache_ptr) {
  vector<vector<int>> cache = *cache_ptr;
  const Coordinate start{0,0};
  //cout << ++call << endl;
  if (!curr.isValid(matrix)) return 0;
  if (curr == start) return 1;
  if (cache[curr.x][curr.y] < 0) cache[curr.x][curr.y] = countTraversalCache(matrix, {curr.x-1,curr.y}, cache_ptr) +
				                         countTraversalCache(matrix, {curr.x, curr.y-1}, cache_ptr);
  return cache[curr.x][curr.y];
}

int countTraversalCache (const vector<vector<int>>& matrix, Coordinate curr) {
  vector<vector<int>> cache(matrix.size(),vector<int>(matrix[0].size(),-1));
  return countTraversalCache(matrix, {static_cast<int>(matrix.size()-1), static_cast<int>(matrix[0].size()-1)}, &cache);
}

//Solution 3:
//dp with table (bottom up)
//O(n*m)
int countTraversalTabular (const vector<vector<int>>& matrix) {

  vector<vector<int>> table(matrix.size(),vector<int>(matrix[0].size()));

  for (int i = 0; i < table.size(); ++i) table[i][0] = 1;
  for (int i = 0; i < table[0].size(); ++i) table[0][i] = 1;
  
  for (int i = 1; i < matrix.size(); ++i) {
    for (int j = 1; j < matrix[0].size(); ++j) {
      table[i][j] = table[i][j-1] + table[i-1][j];
      cout << table[i][j] << " ";
    }
    cout << endl;
  }
  return table[matrix.size()-1][matrix[0].size()-1];
}

int main (void) {
  vector<vector<int>> matrix(5,vector<int>(5));
  cout << countTraversalTabular(matrix);

}

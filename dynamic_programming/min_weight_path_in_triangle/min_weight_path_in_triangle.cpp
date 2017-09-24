//algorithm to find the minimum weight path top-down in a triangle
//Assumptions:
//1) triangle is defined as an array of array of integers so that
//the size of the n-th array is n

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
#if 0
//backtracking
//row = current array, col = element in the current array
int findMinPath (const vector<vector<int>>& triangle, int row, int col) {
  //base case
  if (row == triangle.size()) return 0;
  int min_weight = min(findMinPath(triangle,row+1,col),findMinPath(triangle,row+1,col+1));
   cout << cnt++ << endl;
  return min_weight += triangle[row][col];  
}

int findMinPath (const vector<vector<int>>& triangle) {
  return findMinPath(triangle, 0, 0);
}
#endif

//cache
//row = current array, col = element in the current array
int findMinPath (const vector<vector<int>>& triangle, int row, int col, vector<vector<int>>* cache_ptr) {
  //base case
  if (row == triangle.size()) return 0;
  vector<vector<int>>& cache = *cache_ptr;
  if (cache[row][col] < 0) cache[row][col] = triangle[row][col] + findMinPath(triangle,row+1,col, cache_ptr);
  if (cache[row][col+1] < 0) cache[row][col+1] = triangle[row][col] + findMinPath(triangle,row+1,col+1, cache_ptr);
  return min(cache[row][col], cache[row][col+1]);
}

int findMinPath (const vector<vector<int>>& triangle) {
  vector<vector<int>> cache{};
  for (int row = 0; row < triangle.size(); ++row) cache.emplace_back(triangle[row].size(),-1);
  return findMinPath(triangle, 0, 0, &cache);
}

int main (void) {
  vector<vector<int>> triangle{{2},{4,4},{8,5,6},{4,2,6,2},{1,5,2,3,4}};
  cout << findMinPath(triangle);
}

//algorithm to find if 1 1D pattern exist in a 2d matrix
#include <iostream>
#include <vector>

using namespace std;

//Solution 1
//naive recursion
int call = 0;
bool containPattern (const vector<vector<int>>& matrix, const vector<int>& pattern, int m_x, int m_y, int p) {
  cout << ++call << " " << m_x << " " << m_y << " " << p << endl;
  //pattern has been found
  if (p == pattern.size()) return true;
  
  //check input validity
  if (m_x < 0 || m_y < 0 || m_x >= matrix.size() || m_y >= matrix.size() || matrix[m_x][m_y] != pattern[p]) return false;

  return (containPattern(matrix, pattern, m_x-1, m_y, p+1) || //up
	  containPattern(matrix, pattern, m_x, m_y+1, p+1) || //left
	  containPattern(matrix, pattern, m_x+1, m_y, p+1) || //down
	  containPattern(matrix, pattern, m_x, m_y-1, p+1)); //right
  
}

bool containPattern (const vector<vector<int>>& matrix, const vector<int>& pattern) {
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[0].size(); ++j) {
      if (containPattern(matrix, pattern, i, j, 0)) return true;
    }
  }
  return false;
}

//Solution 2
//dp with caching
bool containPatternCache (const vector<vector<int>>& matrix, const vector<int>& pattern, int m_x, int m_y, int p,
			  vector<vector<vector<int>>>& cache) {
  cout << ++call << " " << m_x << " " << m_y << " " << p << endl;
  //pattern has been found
  if (p == pattern.size()) return true;
  
  //check input validity
  if (m_x < 0 || m_y < 0 || m_x >= matrix.size() || m_y >= matrix.size() || cache[m_x][m_y][p] != -1) return false;

  return  matrix[m_x][m_y] == pattern[p] &&
    (containPattern(matrix, pattern, m_x-1, m_y, p+1) || //up
     containPattern(matrix, pattern, m_x, m_y+1, p+1) || //left
     containPattern(matrix, pattern, m_x+1, m_y, p+1) || //down
     containPattern(matrix, pattern, m_x, m_y-1, p+1)); //right
  
}

bool containPatternCache (const vector<vector<int>>& matrix, const vector<int>& pattern) {
  vector<vector<vector<int>>> cache(matrix.size(), vector<vector<int>>(matrix[0].size(), vector<int>(pattern.size(),-1))); 
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[0].size(); ++j) {
      if (containPatternCache(matrix, pattern, i, j, 0, cache)) return true;
    }
  }
  return false;
}

int main (void) {
  vector<vector<int>> matrix { {1, 2, 3}, {3, 4, 5}, {5, 6, 7}};
  //vector<int> pattern{1,3,4,6};
  vector<int> pattern{1,2,3,4};
  cout << containPattern(matrix, pattern);
}

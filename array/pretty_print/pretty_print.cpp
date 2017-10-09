//algorithm to build a 2d matrix of integers so that
//the outermost rectangle is formed by a, then the next outermost is formed by a-1 and so on

#include <vector>

using namespace std;

vector<vector<int>> prettyPrint(int a) {
  if (a < 1) return {};
  int size = (2*a)-1;
  vector<vector<int>> result(size, vector<int>(size,0));
  int l = 0, r = size-1;
    
  while (l<=r) {
    for (int i = l; i <= r; ++i) {
      result[l][i] = a;
      result[i][r] = a;
      result[r][i] = a;
      result[i][l] = a;
    }
    a = a-1;
    l = l+1;
    r = r-1;
  }
  return result;
}

int main (void) {
  prettyPrint(4);
}

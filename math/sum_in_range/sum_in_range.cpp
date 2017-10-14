//algorithm to find the number of continuous subsequences in a given array which have sum S
//in a given range
//O(n^2)

#include <iostream>
#include <vector>

using namespace std;

int numRange(vector<int> &a, int l, int r) {
    
  int cnt = 0;
    
  for (int i = 0; i < a.size(); ++i) {
    int sum = 0;
    for (int j = i; j < a.size() && sum <= r; ++j) {
      sum += a[j];
      if (sum >= l && sum <= r) ++cnt;
    }
  }
  return cnt;
}

int main (void) {
  vector<int> a{10, 5, 1, 0, 2};
  cout << numRange(a,6,8); 
}

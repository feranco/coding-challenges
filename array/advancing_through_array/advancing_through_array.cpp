#include <iostream>
#include <vector>

using std::vector;

bool isEndReachable (const vector<int>& a, int idx) {
  if ((a[idx] + idx) >= a.size()) return true;
  for (int i = a[idx]; i > 0; --i) {
    if (isEndReachable(a, idx + i)) return true;
  }
  return false;
}

int main (void) {
  vector<int> a{{3,3,1,0,2,0,1}};
  std::cout << isEndReachable(a,0);

  vector<int> b{{3,2,0,0,2,0,1}};
  std::cout << isEndReachable(b,0);
}

//algorithm to compute the index of the first element equal to a target value in a sorted array
//O(log(n))

#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::vector;

template <typename T>
int firstOccurrence(const T& target, const vector<T>& a) {

  int l = 0, r = a.size() - 1,  m = -1;

  while (l <= r) {
    m = l + ((r - l) * 0.5);
    if (a[m] == target) break;
    if (a[m] < target) l = m + 1;
    else r = m - 1;
  }

  if (l > r) return -1;
  while (m > 0 && a[m - 1] == target) m--;

  return m;
}

template <typename T>
int firstOccurrence(const T& target, const vector<T>& a) {

  int l = 0, r = a.size() - 1,  idx = -1;

  while (l <= r) {
    int m = l + ((r - l) * 0.5);
    if (a[m] == target) idx = m; 
    if (a[m] < target) l = m + 1;
    else r = m - 1;
  }

  return idx;
}

int main(void) {
  //vector<int> seq{-14,-10,2,108,108,243,285,285,285,401};
  vector<int> seq{ 108,108,108,108,108,108,108,108,108,108 };
  cout << firstOccurrence(108, seq);
}


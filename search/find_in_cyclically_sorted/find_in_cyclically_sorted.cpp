//algorithm to find the smallest element of a cyclically sorted array
//O(log(n)) time O(1)space

#include <array>
#include <iostream>
#include <random>

using std::array;
using std::cout;

/*
template <typename T, std::size_t SIZE = 10>
T findSmallest(const array<T, SIZE>& a) {
  size_t l = 0, r = a.size() - 1, m;

  while (l < r) {
    m = l + ((r - l) * 0.5);
    if (a[m] > a[r]) l = m + 1; //smallest can't be in [l:m]
    else r = m;  //smallest can't be in [m:r]
  }
  return a[l];
}
*/

template <typename T, std::size_t SIZE = 10>
T findSmallest(const array<T, SIZE>& a) {
  size_t l = 0, r = a.size() - 1, m;

  while (l < r) {
    m = l + ((r - l) * 0.5);
    if (a[m] < a[l]) r = m;  //smallest can't be in [m+1:r]
    else l = m + 1; //smallest can't be in [l:m]
  }
  return a[l];
}

int main(void) {
  array<int,10> seq{{378,478,550,651,103,203,220,235,278,345}};
	cout << findSmallest(seq);
}

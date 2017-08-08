//algorithm to compute the k largest element of an array
//time O(n) space O(1)

#include <array>
#include <iostream>
#include <random>

using std::array;
using std::cout;
using std::default_random_engine;

//partition array a around p index; at the end
//all element lower than a[p] are on the left side
//all element greater than a[p] are on the right side
template <typename T, std::size_t SIZE = 10>
size_t partition(array<T, SIZE>* a_ptr, size_t l, size_t r, size_t p) {
  vector<int>& a = *a_ptr;
  std::swap(a[p], a[r]);
  p = l;//p is the position of the next element lower than pivot
  for (size_t i = l; i < r; ++i) {
    if (a[i] < a[r]) {
      std::swap(a[i], a[p++]);
    }
  }
  //after the cycle p is the position of the pivot
  std::swap(a[p], a[r]);

  return p;
}

#if 0
//alternative partition implementation
//swap on both side of the array
template <typename T, std::size_t SIZE = 10>
size_t partition(array<T, SIZE>* a_ptr, size_t l, size_t r, size_t p) {
  vector<int>& a = *a_ptr;
  std::swap(a[p], a[r]);
  p = r;
  while (r > l) {
    if (a[r - 1] > a[p]) {
      std::swap(a[r - 1], a[p]);
      p = --r;
    }
    else {
      std::swap(a[l], a[r - 1]);
      l++;
    }
  }
  return p;
}
#endif

template <typename T, std::size_t SIZE = 10>
T kLargestElementHelper(array<T, SIZE>* a_ptr, size_t l, size_t r, size_t k) {
  vector<int>& a = *a_ptr;
  default_random_engine ran{};

  while (l <= r) {
    size_t pivot_idx = partition(a, l, r, std::uniform_int_distribution<int>{ static_cast<int>(l), static_cast<int>(r) }(ran));

    if (pivot_idx == a.size() - k) return a[pivot_idx];
    if (pivot_idx > a.size() - k) r = pivot_idx - 1;
    else l =pivot_idx + 1;
  }
}

#if 0
//alternative partition implementation
//recursive
template <typename T, std::size_t SIZE = 10>
T kLargestElementHelper(array<T, SIZE>* a_ptr, size_t l, size_t r, size_t k) {
  vector<int>& a = *a_ptr;
  default_random_engine ran{};
  size_t pivot_idx = partition(a, l, r, std::uniform_int_distribution<int>{ static_cast<int>(l), static_cast<int>(r) }(ran));

  if (pivot_idx == a.size() - k) return a[pivot_idx];
  if (pivot_idx > a.size() - k) return kLargestElementHelper(a, l, pivot_idx - 1, k);
  else return kLargestElementHelper(a, pivot_idx + 1, r, k);
}
#endif

template <typename T, std::size_t SIZE = 10>
T kLargestElement(array<T, SIZE>* a_ptr, size_t k) {
  return kLargestElementHelper(a, 0, a.size() - 1, k);
}


int main(void) {
  array<int,5> seq{3,2,1,5,4};
  cout << kLargestElement(seq, 5);
}



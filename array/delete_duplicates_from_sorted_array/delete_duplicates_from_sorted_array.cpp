//algorithm to delete duplicates from a sorted array
//assumptions:
//1) the array contains integers
//2) remaining elements after duplicates removal are shifted to left
//3) value of remaining element after left shift don't caro

#include <array>
#include <iostream>

using std::array;
using std::cout;

//O(n) time and O(1) space
template<std::size_t SIZE>
int deleteDuplicates (array<int,SIZE>* a_ptr) {
  array<int,SIZE>& a = *a_ptr;

  if (a.size() <= 1) return a.size();
  
  int r = 1;

  while (a[r] != a[r-1]) ++r;
  int w = r;
  ++r;

  for (; r <= a.size()-1; ++r) {
    if (a[r] != a[w]) a[w++] = a[r];
  }
  
  return w;
}

int main (void) {
  array<int,9> n{{2,3,5,5,7,11,11,11,13}};
  std::cout << deleteDuplicates(&n) << "\n";
  for (auto x : n) cout << x << " ";
}

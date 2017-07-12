// algorithm to partition an array in three parts given an input index 
// first part is 

// assumption: 
// 1) the array contains integers


#include <iostream>
#include <array>
#include <utility>

using std::array;
using std::cout;
using std::swap;

const size_t size = 7;

void partition(array<int, size>* a_ptr, int idx) {
  
	array<int, size>& a = *a_ptr;
	
	if (idx >= a.size()) return;

	int p = a[idx];
	swap(a[idx], a[0]);
	int l, m, r;
	l = 0;
	r = a.size() - 1;
	m = 1;
	while (m <= r) {
	  while (a[m] < p) { swap(a[l], a[m]); ++l; ++m; }
	  while (a[m] == p) { ++m; }
	  while (a[m] > p) { swap(a[r], a[m]); --r; }
	}
}

int main(void) {
  array<int, size> arr{{0,1,2,0,2,1,1}};
  partition(&arr, 1);
  for (int x : arr) cout << x << " ";
}

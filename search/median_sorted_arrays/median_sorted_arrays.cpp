//algorithm to find the median of two sorted arrays without merging them
//O(log(m+n)) where m,n are array sizes

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

double findMedianSortedArraysAux(const vector<int> &a, const vector<int> &b) {
  int m = a.size(), n = b.size();

  //bounds on index i:
  //if i = 0 the left part of has no elements
  //if i = m the right part of a has no elements
  int l = 0, r = m;
  
  while (l <= r) {
    //try a new value for i
    int i = l + (r-l)/2;
    //comput j as function of i
    int j = ((m + n + 1) / 2) - i;
    //go left if the last element of the left part of a is greater than
    //the first element of the right part of b
    if (i > 0 && j < n && a[i-1] > b[j]) r = i-1;
    //go right if the last element of the left part of b is greater than
    //the first element of the right part of a
    else if (j > 0 && i < m && b[j-1] > a[i]) l = i+1;
    else {
      //values of i, j allowing to compute the median found
      if ((m+n)%2 != 0) {
	if (i == 0) return b[j-1];
	if (j == 0) return a[i-1];
	return max(a[i-1],b[j-1]);
      }
      else {
	int x = (i > 0) ? a[i-1] : numeric_limits<int>::min();
	int y = (j > 0) ? b[j-1] : numeric_limits<int>::min();
	int z = (i < m) ? a[i] : numeric_limits<int>::max();
	int w = (j < n) ? b[j] : numeric_limits<int>::max();
	return (double)(max(x,y) + min(z,w)) /2;
      }
    }
  }
  return -1.0;
} 
  
double findMedianSortedArrays(const vector<int> &a, const vector<int> &b) {
  //swap a and b if b has less elements than a
  if (a.size() <= b.size()) return findMedianSortedArraysAux(a,b);
  else return findMedianSortedArraysAux(b,a);
}

int main (void) {
    vector<int> l{-2 };
    vector<int> r{-43, -25, -18, -15, -10, 9, 39, 40};
    cout << findMedianSortedArrays(l,r);
}

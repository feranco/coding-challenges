//algorithm to compute the largest integer whose square is less than
//or equal to a given integer k
//assumptions:
//1) use of sqrt is not allowed
//O(log(n)) time O(1)space

#include <iostream>

long squareRoot (long k) {
  int l = 0, r = k, res = 0;
  //saving the result in res is not necessary because if m is the square root
  //all further step will fall in the case square > k and the square root is l-1
  while (l <= r) {
    int m = l + ((r-l) / 2);
    int square = m * m;
    if (square > k) r = m-1;//square root can't be in [m:r]
    else {
      res = square;//continue look in [m+1:r]
      l = m+1;
    }
  }
  return res;
}

int main (void) {
  std::cout << squareRoot(21);
}

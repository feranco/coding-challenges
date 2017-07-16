/*
struct Coordinate {
  int row, col;
  Coordinate (int r, c): row(r), col(c){}
  bool isValid (int a[], int m, int n);
};

bool Coordinate::isValid (int a[], int m, int n) {
  if (row >= 0 && col >= 0 && row < m && col < n) return true;
  return false;
}

bool findElement (int a[][], int m, int n, Coordinate UpLeft, Coordinate DownRight, int x) {
  if (!UpLeft.isValid(a, m, n) || !DownRight.isValid(a, m, n)) return false;
  
}
*/

#include <iostream>

bool findElement (int a[][4], int target, int m, int n) {
  int i = 0;
  int j = n-1;

  while (i < m && j >= 0) {
    int l = 0;
    int r = j;

    while (l <= r) {
      int p = (l+r)/2;
      if (a[i][p] == target) return true;
      if (a[i][p] > target) r = p-1;
      else l = p+1;
    }
    i++;
    j = r;
  }
  return false;
}

int main (void) {
  int arr[4][4] = {
    {15, 20, 40, 85},
    {20, 35, 80, 95},
    {30, 55, 95, 105},
    {43, 80, 100, 120}
  };

  std::cout << findElement(arr, 43, 4, 4);
}

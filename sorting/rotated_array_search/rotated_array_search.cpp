#include <iostream>

using std::cout;

int search (int a[], int x, int l, int r) {
  
  if (r < l) return -1; //x is not in a

  int m = (l+r)/2;
  if (x == a[m]) return m;

  if (a[l] == a[m] && a[m] == a[r]) {
    int r1 = search(a,x,l,m-1);
    int r2 = search(a,x,m+1,r);
    if(r1 < 0 && r2 < 0) return -1;
    else return (r1 >= 0) ? r1 : r2;
  }

  if (a[l] <= a[m]) {
    if (a[l] < x && x < a[m]) return search(a,x,l,m-1);
    else return search(a,x,m+1,r);
  }
  else {
    if (a[m] < x && x < a[r]) return search(a,x,m+1,r);
    else return search(a,x,l,m-1);
  }
}

int main (void) {
  int a[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
  cout << search(a, 5, 0, 11) << "\n";
  cout << search(a, 17, 0, 11) <<"\n";
  int b[] = {15, 16, 19, 20, 25, 1, 1, 1, 1, 1, 1, 11};
  cout << search(b, 5, 0, 11) << "\n";
  cout << search(b, 19, 0, 11) << "\n";
  int c[] = {1, 16, 19, 20, 25, 1, 1, 1, 1, 1, 1,  1};
  cout << search(c, 5, 0, 11) << "\n";
  cout << search(c, 19, 0, 11) << "\n";
}

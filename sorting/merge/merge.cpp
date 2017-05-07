#include <iostream>

using std::cout;

const int sz_a = 10;
const int sz_b = 4;

//a and b are already sorted
//merge b in a assuming that a has enough space
void merge (int a[], int r_a, int b[], int r_b) {
  int idx = r_a + r_b + 1;

  while (r_a >= 0 && r_b >= 0) {
    if (a[r_a] > b[r_b]) a[idx--] = a[r_a--];
    else  a[idx--] = b[r_b--];
  }
  while (r_b >= 0) a[idx--] = b[r_b--];
}

int main (int argc, const char* argv[]) {
  int a[sz_a] = {1, 3, 7, 8, 9};
  int b[sz_b] = {2, 5, 6, 10};
  merge(a, 4, b, 3);
  for (int i = 0; i < sz_a; ++i) cout << a[i] << " ";
}

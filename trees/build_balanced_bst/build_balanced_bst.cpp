// algorithm to build a minimum height bst given a sorted array

// assumption: 
// 1) trees nodes are integer

#include "../common/utility.h"

Link buildBST (int a[], int l, int r) {
  if (r < l)  return 0;
  int m = (l + r) / 2;
  Link v = new BtNode(a[m]);
  v->left  = buildBST (a, l, m-1);
  v->right = buildBST(a, m+1, r);
  return v;
}

int main(void) {
  int a[] = {1, 3, 6, 8, 10, 13, 15, 17, 18, 20, 22, 23};
  Link bst = buildBST(a, 0, 11);
  dump(cout , bst, 0);
}


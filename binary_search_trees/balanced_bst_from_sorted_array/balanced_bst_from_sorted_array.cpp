//algorithm to build a balance bst from a sorted array
//O(logn) time
#include "../common/defs.h"
#include <iostream>
#include <vector>

using namespace std;

unique_ptr<BstNode<int>> buildBalancedBST (const vector<int>& a, int left, int right) {
  //base case
  if (right < left) return nullptr;
  //find subtree root
  int m = (left + right) / 2;
  unique_ptr<BstNode<int>> root = make_unique<BstNode<int>>(a[m]);
  root->left = buildBalancedBST(a, left, m-1);
  root->right = buildBalancedBST(a, m+1, right);
  return root;
}

int main (void) {
  const vector<int> a{1,2,3,4,5,6,7};
  auto bst = buildBalancedBST(a, 0, a.size()-1);
  dump(bst,0);
}

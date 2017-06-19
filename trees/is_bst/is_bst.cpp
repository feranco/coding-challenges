// algorithm to check if a tree is a binary search tree
// eachthe list k contains all nodes at level k 

// assumption: 
// 1) each node has an integer value with ptr to the left and right children

#include "../common/utility.h"

#include <climits>

bool checkBstNode (Link v, int min, int max) {
  if (v->value >= min && v->value < max) return true;
  return false;
}

bool isBst (Link v, int min, int max) {
  if (!v) return true;
  if(!checkBstNode(v, min, max)) return false;
  return (isBst(v->left, min, v->value) && isBst(v->right, v->value, max));
}

bool isBst (Link root) {
  int min_threshold = INT_MIN;
  int max_threshold = INT_MAX;
  return isBst(root, min_threshold, max_threshold);
}

int main (void) {
  int  bst_val[] = {4,2,1,-1,-1,3,-1,-1,6,5,-1,-1,7,-1,-1};
  Link bst = 0;
  bool result = true;
  buildBtree(bst, bst_val);
  dump(cout, bst, 0);
  cout << isBst(bst) << "\n";

  int  not_bst_val[] = {4,2,1,-1,-1,8,-1,-1,6,5,-1,-1,7,-1,-1};
  Link not_bst = 0;
  result = true;
  buildBtree(not_bst, not_bst_val);
  dump(cout, not_bst, 0);
  cout << isBst(not_bst) << "\n";
}

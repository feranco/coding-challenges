// algorithm to check if a binary tree is balanced

// assumption: 
// 1) tree is binary  tree
// 2) each node has an integer value with ptr to the left and right children

#include "../common/utility.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;

int isBalancedR (Link v) {
  if (!v) return 0;
  int hl = isBalancedR(v->left);
  //if (hl < 0) return -1; better do not check right if not necessary
  int hr = isBalancedR(v->right);
  if (hr < 0 || hl < 0) return -1; 
  if (std::abs(hl-hr)>1) return -1;
  else return 1 + std::max(hl, hr);
}

bool isBalanced (Link root) {
  if (isBalancedR(root) < 0) return false;
  else return true;
}

int main (void) {
  int  unbalanced[] = {4,2,-1,-1,1,3,5,7,-1,-1,-1,-1,6,-1,-1};
  Link unbal_tree = 0;
  buildBtree(unbal_tree,  unbalanced);
  dump(cout, unbal_tree, 0);
  cout << isBalanced(unbal_tree) << "/n";

  int  balanced[] = {4,2,1,-1,-1,3,-1,-1,6,5,-1,-1,7,-1,-1};
  Link bal_tree = 0;
  buildBtree(bal_tree,  balanced);
  dump(cout, bal_tree, 0);
  cout << isBalanced(bal_tree) << "/n";

}



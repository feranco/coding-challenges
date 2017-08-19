//algorithms to chech if a binary tree is a bst
//1) check top down if each node respect the bst rule;
// update the max going left and the min going right
//2) check bottom up if each node respect the bst rule
//update both min and max going up
#include "../common/defs.h"
#include <iostream>
#include <limits>

using namespace std;

bool BstTestHelper (const unique_ptr<BstNode<int>>& root, int min, int max) {
  if (!root) return true;

  if (root->data >= min && root->data < max) {
    return (BstTestHelper(root->left, min, root->data) &&
      BstTestHelper(root->right, root->data, max));
  }

  return false;
}

bool BstTest (const unique_ptr<BstNode<int>>& root) {
  return BstTestHelper(root, numeric_limits<int>::min(), numeric_limits<int>::max());
}

int main(void) {
  auto tree = buildTestBst();
  cout << BstTest(tree);
}

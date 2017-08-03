//algorithm to compute the right sibling of each node in a perfectly balanced tree
//first solution: post_order traversal time O(n) space O(h)
//second solution: 


#include <iostream>
#include "../../binary_trees/common/defs.h"

using std::cout;

#if 0
//first solution
void computeRightSiblingHelper (unique_ptr<BtNode<char>>& left, unique_ptr<BtNode<char>>& right) {
  if (!left || !right) return;
  left->sibling = right.get();
  computeRightSiblingHelper(left->right, right->left);
}

void computeRightSibling (unique_ptr<BtNode<char>>& root) {
  if (root->left) computeRightSibling(root->left);
  if (root->right) computeRightSibling(root->right);
  computeRightSiblingHelper(root->left, root->right);
}
#endif

//second solution
void computeRightSiblingHelper (BtNode<char>>* current) {

  while (current) {
    current->left->sibling = current->right.get();

    if (current->sibling) {
      current->right->sibling = current->sibling.get();
  }
    current = current->sibling;
  }
}

void computeRightSibling (unique_ptr<BtNode<char>>& root) {
  auto current = root.get();
  while (current->left) computeRightSiblingHelper(current);
}

int main(void) {
  auto tree = buildBalancedBtree();
  computeRightSibling(tree);
}

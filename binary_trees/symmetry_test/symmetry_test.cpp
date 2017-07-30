//algorithm to check if a binary tree is simmetric
//time O(n), space O(h)

#include <iostream>
#include "../../binary_trees/common/defs.h"

using std::cout;
using std::unique_ptr;

bool checkSymmetry (const unique_ptr<BtNode<int>>& left, const unique_ptr<BtNode<int>>& right) {
  if (!left && !right) return true;
  if (left && right && left->data == right->data) {
    return checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left);
  }
  return false;
}

//assume that parent node is available
bool isSymmetric (const unique_ptr<BtNode<int>>& root) {
  return (root == nullptr) ? true : checkSymmetry(root->left, root->right);
}

#include <stack>
using std::stack;

bool isSymmetricIt (const unique_ptr<BtNode<int>>& root) {
  if (!root) return true;
  
  stack<BtNode<int>*> s_left, s_right;
  s_left.push(root->left.get()), s_right.push(root->right.get());
  while (!s_left.empty() && !s_right.empty()) {
    auto l = s_left.top();
    auto r = s_right.top();
    if(!l && !r) {
      s_left.pop(), s_right.pop();
      continue;
    }
    if (l && r && l->data == r->data ) {
      s_left.pop(), s_right.pop();
      s_left.push(l->left.get()), s_right.push(r->right.get());
      s_left.push(l->right.get()), s_right.push(r->left.get());
      continue;
    }
    return false;
  }
  return true;
}

int main(void) {
  auto tree = buildSymmetricBtree();
  cout << isSymmetric(tree);
   cout << isSymmetricIt(tree);
}



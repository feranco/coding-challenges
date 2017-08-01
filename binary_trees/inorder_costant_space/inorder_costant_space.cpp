//algorithm to perform inorder traversal in costant space
//time O(n), space O(1)
//Assumptions:
//1) tree nodes have pointers to parents

#include <iostream>
#include <unordered_map>
#include <vector>
#include "../../binary_trees/common/defs.h"

using std::cout;
using std::unique_ptr;
using std::vector;

vector<char> inorderTraversal (const unique_ptr<BtNode<char>>& root) {
  vector<char> traversal;
  auto iter = root.get();

  while (true) {
    while (iter->left) iter = iter->left;
    traversal.push_back(iter->data);
    if (iter->right) {
      iter = iter->right;
      continue;
    }
    else {
      auto child = iter;
      iter = iter->parent;
      if (iter->left == child) // traversal.push_back(iter->data) and go right
      else //go to parent
    }
  }
}

/*
vector<char> inorderTraversal (const unique_ptr<BtNode<char>>& root) {
  vector<char> traversal;
  auto iter = root.get();

  while (true) {
    while (iter->left) iter = iter->left;
    traversal.push_back(iter->data);
    if (iter->right) {
      iter = iter->right;
      continue;
    }
    else {
      auto child = iter;
      iter = iter->parent;
      if (iter->left == child) //go right
      else //go to parent
    }
  }
}
*/

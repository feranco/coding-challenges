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
    
  while (true) {// go down
    while (iter->left) iter = iter->left.get();
    traversal.push_back(iter->data);
    if (iter->right) {
      iter = iter->right.get();
      continue;
    }
    else {//go up
      auto child = iter;
      iter = iter->parent;
      while (true) {
	
	if (iter->left.get() == child) {
	  traversal.push_back(iter->data);
	  if (iter->right.get()) {iter = iter->right.get(); break;}
	}
                
	if (iter->right.get() == child && iter == root.get()) return traversal;
                
	child = iter;
	iter = iter->parent;           
      }
    }
  }
}

int main (void) {
  auto tree = buildCharBtree();
  auto inorder = inorderTraversal(tree);
}

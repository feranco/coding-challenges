//algorithm to perform inorder traversal in costant space
//time O(n), space O(1)
//Assumptions:
//1) tree nodes have pointers to parents

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../../binary_trees/common/defs.h"

using std::cout;
using std::unique_ptr;
using std::vector;

enum class State {DOWN, UP, EXIT};

vector<char> inorderTraversal (const unique_ptr<BtNode<char>>& root) {
  vector<char> traversal;
  auto iter = root.get();
  State state = State::DOWN;
    
  while (state != State::EXIT) {// go down

    if (state == State::DOWN) {
      while (iter->left) iter = iter->left.get();
      traversal.push_back(iter->data);
      if (iter->right) iter = iter->right.get();
      else state = State::UP;
    }

    if (state == State::UP) {//go up
      auto child = iter;
      iter = iter->parent;
	
      if (iter->left.get() == child) {
	traversal.push_back(iter->data);
	if (iter->right.get()) {iter = iter->right.get(); state = State::DOWN; continue;}
      }
                
      if (iter->right.get() == child && iter == root.get()) state = State::EXIT;                        
    }
  }
  return traversal;
}

int main (void) {
  auto tree = buildCharBtree();
  auto inorder = inorderTraversal(tree);
  std::for_each(inorder.begin(),inorder.end(),[](const char& n){cout << n << "\n";});
}

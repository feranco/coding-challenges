//algorithm to build a binary tree from its preorder traversal
//time O(n) space O(h)
//Assumptions:
//no child is marked with nullptr

#include <iostream>
#include <vector>
#include "../../binary_trees/common/defs.h"

using std::cout;
using std::vector;

//with ptr
unique_ptr<BtNode<char>> buildFromPreorderHelper(const vector<char*>& pre, int* idx) {
  char* data = pre[(*idx)++];
  if (!data)  return nullptr; 
  unique_ptr<BtNode<char>> current(new BtNode<char>(*data));
  current->left = buildFromPreorderHelper(pre, idx);
  current->right = buildFromPreorderHelper(pre, idx);
  return current;
}

unique_ptr<BtNode<char>> buildFromPreorder(const vector<char*>& pre) {
  int idx = 0;
  return buildFromPreorderHelper(pre, &idx);
}

#if 0
//with reference
unique_ptr<BtNode<char>> buildFromPreorderHelper (const vector<char*>& pre, int& idx) {
  if (!pre[idx]) {idx++; return nullptr;}
  unique_ptr<BtNode<char>> current(new BtNode<char>(*pre[idx]));
  current->left = buildFromPreorderHelper(pre, ++idx);
  current->right = buildFromPreorderHelper(pre, ++idx);
  return current;
}

unique_ptr<BtNode<char>> buildFromPreorder (const vector<char*>& pre) {
  int idx = 0;
  return buildFromPreorderHelper (pre, idx);
}
#endif

int main (void) {
  vector<char*> preorder{new char('H'),new char('B'),new char('F'), nullptr, nullptr, new char('E'), 
      new char('A'), nullptr, nullptr, nullptr, new char('C'), nullptr, new char('D'), nullptr, 
      new char('G'), new char('I'), nullptr, nullptr, nullptr };
  auto tree =   buildFromPreorder(preorder);
}


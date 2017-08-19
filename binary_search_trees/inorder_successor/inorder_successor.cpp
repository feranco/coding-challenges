//algorithm to find the greater element of a value k in a BST
//O(h)
#include "../common/defs.h"
#include <iostream>

using namespace std;

BstNode<int>* findMin (const unique_ptr<BstNode<int>>& root) {
  auto it = root.get();
  while (it->left) it = it->left.get();
  return it;
}

//solution 1: with recursion (an extra parameter is needed to track the best node cadidate examined so far)
BstNode<int>* inorderSuccessor (const unique_ptr<BstNode<int>>& root, int k, BstNode<int>* candidate) {
  //if root < k go right;
  //if root > k go left and save root as pssible successor
  //if root == k find min of right subtree and return it
  //if not exist return the saved possible successor

  if (!root) return nullptr; // k is not in the tree
  BstNode<int>* res = nullptr;
  if (root->data < k) res = inorderSuccessor(root->right,k,candidate);
  else if (root->data > k) {
    candidate = root.get();
    res = inorderSuccessor(root->left,k,candidate);
  }
  else {
    if (root->right) res = findMin(root->right);
    else res = candidate;
  }
  return res;
}

//solution 2: iterative
BstNode<int>* inorderSuccessor (const unique_ptr<BstNode<int>>& root, int k) {
  
  BstNode<int> *it = root.get(), *candidate = nullptr;
  
  while (it) {
    if (it->data < k) it = it->right.get();
    else if (it->data > k) {
      candidate = it;
      it = it->left.get();
    }
    else if (it->right) {
      //this step is not strictly necessary:
      //continuing iterate until a leaf and update candidate has the same effect
      candidate = findMin(it->right);
      break;
    }
  }
  return candidate;
}

int main(void) {
  auto tree = buildTestBst();
  auto successor = inorderSuccessor(tree,23);
  if (successor) cout << successor->data;
}

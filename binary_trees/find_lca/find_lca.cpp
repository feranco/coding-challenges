//algorithm to find the lowest common ancestor of two node in a binary tree
//O(h) time, O(n) space

#include <cstdlib>
#include <iostream>
#include <utility>
#include "../../binary_trees/common/defs.h"

using std::cout;
using std::unique_ptr;

//assume that parent node is available
BtNode<int>* findLCA (const unique_ptr<BtNode<int>>& a, const unique_ptr<BtNode<int>>& b) {

  int height_a = 0, height_b = 0;

  //compute height of input nodes
  for (auto p = a->parent; p != nullptr; p = p->parent) ++height_a;
  for (auto p = b->parent; p != nullptr; p = p->parent) ++height_b;

  //put the node with pax height in a
  auto p_a = a.get(), p_b = b.get();
  if (height_b > height_a) std::swap(p_a, p_b);

  //bring both nodes to the same level
  int height_diff = abs(height_a-height_b);
  while (height_diff--) p_a = p_a->parent;

  //go toward the root until lca is found
  while (p_a != p_b) {
    p_a = p_a->parent;
    p_b = p_b->parent;
  }

  return p_a;
}

struct LCAinfo {
  BtNode<int>* lca;
  int n_found;
};

//assume that parent node is not available
LCAinfo findLCAhelper (const unique_ptr<BtNode<int>>& root,
		      const unique_ptr<BtNode<int>>& a, const unique_ptr<BtNode<int>>& b) {
  
  if (!root) return {nullptr, 0};

  //check immediately if the current node is a (or b) allow to stop
  //the recursion if b (or a) is a left successor 
  int n_found = 0;
  if (root == a || root == b) n_found++;

  //check left
  auto info_left = findLCAhelper(root->left, a, b);
  if (info_left.n_found == 2) return info_left;
  n_found += info_left.n_found;
  if (n_found == 2) return {root.get(),n_found}; //stop recursion if not necessary

  //check right
  auto  info_right = findLCAhelper(root->right, a, b);
  if (info_right.n_found == 2) return info_right;
  n_found += info_right.n_found;

  return {n_found == 2 ? root.get() : nullptr, n_found};
}


//assume that parent node is available
BtNode<int>* findLCA (const unique_ptr<BtNode<int>>& root,
		       const unique_ptr<BtNode<int>>& a, const unique_ptr<BtNode<int>>& b) {
  return findLCAhelper(root, a, b).lca;
}

int main (void) {
  auto root = buildTestBtree();
  auto lca = findLCA(root->left->left->left, root->left->right->right->left);
  cout << lca->data;

  auto lca_2 = findLCA(root,root->left->left->left, root->left->right->right->left);
  cout << lca_2->data;
}

//algorithm to find the lca
//O(h)
#include "../common/defs.h"
#include <iostream>

using namespace std;

BstNode<int>* findLCArec(const unique_ptr<BstNode<int>>& root, const unique_ptr<BstNode<int>>& a, const unique_ptr<BstNode<int>>& b) {
	if (a->data < root->data && b->data < root->data) return findLCA(root->left, a, b);
	if (a->data > root->data && b->data > root->data) return findLCA(root->right, a, b);
	//in all remaining cases the lca is the current node:
	//1) if a < current and b > current or viceversa
	//2) if a == current or b == current
	return root.get();
}


BstNode<int>* findLCAit(const unique_ptr<BstNode<int>>& root, const unique_ptr<BstNode<int>>& a, const unique_ptr<BstNode<int>>& b) {
	auto it = root.get();
	while (it) {
		if (a->data < it->data && b->data < it->data) it = it->left.get();
		else if (a->data > it->data && b->data > it->data) it = it->right.get();
		else break;
	}
	return it;
}

int main(void) {
  auto tree = buildTestBst();
  auto lca_it = findLCAit(tree, tree->left->left, tree->left->right->right);
  auto lca_rec = findLCArec(tree, tree->left, tree->left->right->right);
  cout << "lca_it: " << lca_it->data << " lca_rec: " << lca_rec->data;
}

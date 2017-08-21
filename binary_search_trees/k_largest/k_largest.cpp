//algorithm to find the k largest element in a bst
//O(h+k)
#include "../common/defs.h"
#include <iostream>

using namespace std;

//reverse inorder traversal: first right, then current, then left
void findKLargest(const unique_ptr<BstNode<int>>& root, unsigned int k, vector<int>* largest) {
  if (!root || largest->size() == k) return;
  findKLargest(root->right, k, largest);
  if (largest->size() < k) largest->emplace_back(root->data);
  findKLargest(root->left, k, largest);
}

vector<int> findKLargest(const unique_ptr<BstNode<int>>& root, int k) {
  vector<int> result;
  findKLargest(root, k, &result);
  return result;
}

int main(void) {
  auto tree = buildTestBst();
  auto k_largest = findKLargest(tree, 2);
  for (const auto k : k_largest) cout << k << " ";
}

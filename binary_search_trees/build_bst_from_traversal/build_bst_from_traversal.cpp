//algorithm to build a bst from its postorder traversal
//O(h)
#include "../common/defs.h"
#include <iostream>
#include <vector>

using namespace std;

/*
unique_ptr<BstNode<int>>  buildBstFromPostorderHelper (const vector<int>& postorder, int start, int end) {
    auto root = make_unique<BstNode<int>>(postorder[end]);
    int idx = end-1;
    for (; idx >= start && (postorder[idx] > (postorder[end])); --idx);
    if (idx < end && idx >= start) root->right = buildBstFromPostorderHelper(postorder, idx+1, end-1);
    if (idx < end && idx >= start) root->left = buildBstFromPostorderHelper(postorder, start, idx);//start < idx?
    return root;
}
*/

//O(n^2) skewed a dx O(n) skewed sx O(nlogn) balanced
unique_ptr<BstNode<int>>  buildBstFromPostorderHelper (const vector<int>& postorder, size_t start, size_t end) {
    auto root = make_unique<BstNode<int>>(postorder[end]);
    int idx = end-1;
    for (; idx > start && (postorder[idx] > (postorder[end])); --idx);
    //put the two if below as condition on the input and return null
    if (idx < end) root->right = buildBstFromPostorderHelper(postorder, idx+1, end-1);
    if (start < idx) root->left = buildBstFromPostorderHelper(postorder, start, idx);//start < idx?
    return root;
}

unique_ptr<BstNode<int>> buildBstFromPostorder (const vector<int>& postorder) {
  unique_ptr<BstNode<int>> root;
  buildBstFromPostorderHelper(postorder, 0, postorder.size()-1, root);
  return root;
}

int main (void) {
  vector<int> postorder {2,5,3,9,17,11,7};
  auto tree = buildBstFromPostorder(postorder);
}

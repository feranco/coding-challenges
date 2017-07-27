//algorithm to test if a binary tree is height-balanced
//assumptions:
//1) height balanced = height of left and right subtrees differs at most 1
//O(n) time, O(h) space

#include <cstdlib>
#include <iostream>
#include "../../binary_trees/common/defs.h"

using std::unique_ptr;

struct BalanceInfo {
  bool balanced;
  int height;
  BalanceInfo (int height, bool balanced) : balanced(balanced),  height(height){}
};

BalanceInfo isHeightBalancedR (const unique_ptr<BtNode<int>>& bt_node) {
  if (!bt_node) return {-1, true};
  auto info_left = isHeightBalancedR(bt_node->left);
  if (!info_left.balanced) return {0, false};
  auto info_right = isHeightBalancedR(bt_node->right);
  if (!info_right.balanced) return {0, false};
  int curr_height = std::max(info_right.height, info_left.height) + 1;
  bool balanced = abs(info_right.height - info_left.height) > 1;
  //std::cout << bt_node->data << " " << info_left.height << " " << info_right.height << std::endl;
  return {curr_height, balanced};
}

bool isHeightBalanced (const unique_ptr<BtNode<int>>& root) {
  auto info = isHeightBalancedR (root);
  return info.balanced;
}

int main (void) {
  auto root = buildTestBtree();
  std::cout << isHeightBalanced(root);
}

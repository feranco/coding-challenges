//algorithm to build a binary tree from its traversal
//time O(n), space O(h)

#include <iostream>
#include <unordered_map>
#include <vector>
#include "../../binary_trees/common/defs.h"

using std::cout;
using std::unique_ptr;
using std::unordered_map;
using std::vector;

unique_ptr<BtNode<char>> buildFromInorderPostorderHelper (const vector<char>& post, size_t post_start, size_t post_end, const unordered_map<char,size_t>& node_to_inorder_idx, size_t in_start, size_t in_end) {
  //check for termination
  if (post_start > post_end || in_start > in_end) return nullptr;

  unique_ptr<BtNode<char>> current_node(new BtNode<char>(post[post_end]));
  size_t size_left = node_to_inorder_idx.at(post[post_end]) - in_start;
  current_node->left = buildFromInorderPostorderHelper(post, post_start, post_start+size_left-1,
							   node_to_inorder_idx, in_start,
							in_start+size_left-1);

  current_node->right = buildFromInorderPostorderHelper(post, post_start+size_left+1, post_end-1,
							   node_to_inorder_idx, in_start+size_left+1,
						      in_end);
  return current_node;
}

unique_ptr<BtNode<char>> buildFromInorderPostorder (const vector<char>& in, const vector<char>& post) {
  unordered_map<char,size_t> node_to_inorder_idx;
  for (size_t idx = 0; idx != in.size(); ++idx) {
    node_to_inorder_idx.insert({in[idx], idx});
  }
  return buildFromInorderPostorderHelper(post, 0, post.size()-1, node_to_inorder_idx, 0, in.size()-1);
}

int main(void) {
  vector<char> inorder{'F','B','A','E','H','C','D','I','G' };
  vector<char> postorder{'F','A','E','B','I','G','D','C','H' };
  auto tree =  buildFromInorderPostorder(inorder, postorder);
}

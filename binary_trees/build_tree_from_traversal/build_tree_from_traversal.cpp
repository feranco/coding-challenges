//algorithm to build a binary tree from its traversal
//time O(n) because unordered map allow fast lookup into inorder, space O(h)
//build from Preorder and Postorder is not possible, because only inorder traversal allow to
//understand if a single child is a left child or a right child

#include <iostream>
#include <unordered_map>
#include <vector>
#include "../../binary_trees/common/defs.h"

using std::cout;
using std::unique_ptr;
using std::unordered_map;
using std::vector;

unique_ptr<BtNode<char>> buildFromInorderPostorderHelper(const vector<char>& post, int post_start, int post_end,
							 const unordered_map<char, size_t>& node_to_inorder_idx,
							 int in_start, int in_end) {
	//check for termination
	if (post_start > post_end || in_start > in_end) return nullptr;

	unique_ptr<BtNode<char>> current_node(new BtNode<char>(post[post_end]));
	size_t size_left = node_to_inorder_idx.at(post[post_end]) - in_start;
	current_node->left = buildFromInorderPostorderHelper(post, post_start, post_start + size_left - 1,
		node_to_inorder_idx, in_start,
		in_start + size_left - 1);

	current_node->right = buildFromInorderPostorderHelper(post, post_start + size_left, post_end - 1,
		node_to_inorder_idx, in_start + size_left + 1,
		in_end);
	return current_node;
}

unique_ptr<BtNode<char>> buildFromInorderPostorder(const vector<char>& in, const vector<char>& post) {
	unordered_map<char, size_t> node_to_inorder_idx;
	for (size_t idx = 0; idx != in.size(); ++idx) {
		node_to_inorder_idx.insert({ in[idx], idx });
	}
	return buildFromInorderPostorderHelper(post, 0, post.size() - 1, node_to_inorder_idx, 0, in.size() - 1);
}

unique_ptr<BtNode<char>> buildFromInorderPreorderHelper(const vector<char>& pre, int pre_start, int pre_end,
							 const unordered_map<char, size_t>& node_to_inorder_idx,
							 int in_start, int in_end) {
	//check for termination
	if (pre_start > pre_end || in_start > in_end) return nullptr;

	unique_ptr<BtNode<char>> current_node(new BtNode<char>(post[pre_start]));
	size_t size_left = node_to_inorder_idx.at(post[pre_start]) - in_start;
	current_node->left = buildFromInorderPostorderHelper(pre, pre_start+1, pre_start+size_left,
		node_to_inorder_idx, in_start,
		in_start + size_left - 1);

	current_node->right = buildFromInorderPostorderHelper(pre, pre_start+size_left+1, pre_end,
		node_to_inorder_idx, in_start + size_left + 1,
		in_end);
	return current_node;
}

unique_ptr<BtNode<char>> buildFromInorderPreorder(const vector<char>& in, const vector<char>& pre) {
	unordered_map<char, size_t> node_to_inorder_idx;
	for (size_t idx = 0; idx != in.size(); ++idx) {
		node_to_inorder_idx.insert({ in[idx], idx });
	}
	return buildFromInorderPostorderHelper(pre, 0, pre.size() - 1, node_to_inorder_idx, 0, in.size() - 1);
}

int main(void) {
  vector<char> inorder{'F','B','A','E','H','C','D','I','G' };
  vector<char> postorder{'F','A','E','B','I','G','D','C','H' };
  vector<char> preorder{'H','B','F','E','A','C','D','G','I' };
  auto tree =   buildFromInorderPostorder(inorder, postorder);
  auto tree2 =  buildFromInorderPreorder(inorder, preorder);
}

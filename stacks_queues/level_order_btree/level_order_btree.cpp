//algorithm to traverse a binary tree in level order
//assumptions:
//1) operand are integers
//2) node of each level are put in a separated array
//O(n) time, O(n) space

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include "../../binary_trees/common/defs.h"

using std::cout;
using std::queue;
using std::unique_ptr;
using std::vector;


vector<vector<int>> btreeLevelOrder(const unique_ptr<BtNode<int>>& root) {
	vector<vector<int>> bt_levels;
	queue<BtNode<int>*> curr_level_nodes({ root.get() });

	while (!curr_level_nodes.empty()) {
		vector<int> curr_level;
		queue<BtNode<int>*> next_level_nodes;
		while (!curr_level_nodes.empty()) {
			auto iter = curr_level_nodes.front();
			curr_level.push_back(iter->data);
			curr_level_nodes.pop();
			if (iter->left)   next_level_nodes.push(iter->left.get());
			if (iter->right)  next_level_nodes.push(iter->right.get());
		}
		bt_levels.push_back(curr_level);
		curr_level_nodes = next_level_nodes;
	}
	return bt_levels;
}

/*
using std::pair;
using std::make_pair;

vector<vector<int>> btreeLevelOrder(const unique_ptr<BtNode<int>>& root) {
	vector<vector<int>> bt_levels;
	queue<pair<BtNode<int>*, int>> bt_nodes({make_pair(root.get(), 0) });

	while (!bt_nodes.empty()) {
		auto iter = bt_nodes.front();
		bt_nodes.pop();
		if (bt_levels.size() == iter.second)  bt_levels.push_back(vector<int>());
		bt_levels[iter.second].push_back(iter.first->data);
		if (iter.first->left)  bt_nodes.push(make_pair(iter.first->left.get(), iter.second+1));
		if (iter.first->right)  bt_nodes.push(make_pair(iter.first->right.get(), iter.second+1));
	}
	return bt_levels;
}
*/

int main (void) {

  auto root = buildTestBtree();
  auto levels = btreeLevelOrder(root);
  int x = 0;
  for (auto level : levels) {
    cout << "level " << x++ << ":";
    std::for_each(level.begin(), level.end(), [](int x) {cout << x << " "; });
    cout << "\n";
  }
}

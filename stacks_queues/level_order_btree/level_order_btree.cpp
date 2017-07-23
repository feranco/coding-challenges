//algorithm to traverse a binary tree in level order
//assumptions:
//1) operand are integers
//2) node of each level are put in a separated array
//O(n) time, O(n) space

#include <iostream>
#include <queue>
#include <utility>

using std::queue;
using std::unique_ptr;
//using std::make_unique;
using std::pair;
using std::make_pair;
using std::vector;

struct Node {
  int value;
  unique_ptr<Node> left, right;
};

vector<vector<int>> btreeLevelOrder (const unique_ptr<Node>& root) {
  vector<vector<int>> bt_levels;
  queue<pair<Node,int>> bt_nodes;
  bt_nodes.push(make_pair(*root,0));
  bt_levels.push_back(vector<int>{root->value});
  return bt_levels;
}

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
using std::pair;
using std::make_pair;
using std::vector;

struct Node {
  int value;
  unique_ptr<Node> left, right;
};

vector<vector<int>> btreeLevelOrder (const unique_ptr<Node>& root) {
  vector<vector<int>> bt_levels;
  queue<Node*> curr_level_nodes({bt_nodes.push});
  
  while (!curr_level_nodes.empty()) {
    vector<int> curr_level;
    queue<Node*> next_level_nodes;
    while (!curr_level_nodes.empty()) {
      auto iter = curr_level_nodes.front();
      curr_level_nodes.pop();
      if (curr_level_nodes->left)   next_level_nodes.push(iter->left.get());
      if (curr_level_nodes->right)  next_level_nodes.push(iter.first->right.get());
    }
    curr_level_nodes = next_level_nodes;
  }
  return bt_levels;
}

vector<vector<int>> btreeLevelOrder (const unique_ptr<Node>& root) {
  vector<vector<int>> bt_levels;
  queue<pair<Node*,int>> bt_nodes;
  bt_nodes.push(make_pair(root.get(),0)); 
  bt_levels.push_back(vector<int>{root->value});
  
  while (!bt_nodes.empty()) {
    auto iter = bt_nodes.front();
    bt_nodes.pop();
    if (bt_levels.size() > iter.second)  bt_levels.push_back(vector<int>());
    bt_levels[iter.second].push_back(iter.first->value);
    if (iter.first->left)  bt_nodes.push(make_pair(iter.first->left.get(),iter.second++));
    if (iter.first->right)  bt_nodes.push(make_pair(iter.first->right.get(),iter.second++));
  }
  return bt_levels;
}

int main (void) {
  
}

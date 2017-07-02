// algorithm to build a h lists given binary tree t of height h
// each list k contains all nodes at level k 

// assumption: 
// 1) tree is binary  tree
// 2) each node has an integer value with ptr to the left and right children

#include "../common/utility.h"

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::max;
using std::list;
using std::vector;

// utility function to print all lists
void dumpBtLevelList (const vector<list<Link>>& levelsList) {
  int i = 0;
  for (const auto level : levelsList) {
    cout << "Level " << i++ << ": ";
    for (const auto node : level) {
      cout << node->value << " ";
    }
    cout << "\n";
  }
}

// build a h lists given binary tree t of height h
// modify preorder traversal to insert each node in the proper list
void btLevelList (Link v, vector<list<Link>>& levelsList, int h) {
  if (!v) return;
  if (levelsList.size() == h) levelsList.push_back(list<Link>());
  levelsList[h].push_back(v);
  btLevelList(v->left, levelsList, h+1);
  btLevelList(v->right, levelsList, h+1);
};

int main (void) {
  int bt_val[] = {4,2,-1,-1,1,3,5,7,-1,-1,-1,-1,6,-1,-1};
  Link bt = 0;
  buildBtree(bt, bt_val);
  vector<list<Link>> levelsList;
  btLevelList(bt, levelsList, 0);
  dumpBtLevelList(levelsList);
}


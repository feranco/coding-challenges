#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::max;
using std::list;
using std::vector;

struct BstNode {
  int value;
  BstNode *left, *right;
  BstNode (int x): value(x), left(0), right(0){}
};

typedef BstNode* BstLink;

void dumpBstLevelList (const vector<list<BstLink>>& levelsList) {
  int i = 0;
  for (const auto level : levelsList) {
    cout << "Level " << i++ << ": ";
    for (const auto node : level) {
      cout << node->value << " ";
    }
    cout << "\n";
  }
}

void buildBst (BstLink& v, int cmd[]) {
  static int idx = 0;
  int t = cmd[idx++];
  if (t < 0) {
    v = 0;
  }
  else {
    v = new BstNode(t);
    buildBst(v->left, cmd);
    buildBst(v->right, cmd);
  }
}

void bstLevelList (BstLink v, vector<list<BstLink>>& levelsList, int h) {
  if (!v) return;
  if (levelsList.size() == h) levelsList.push_back(list<BstLink>());
  levelsList[h].push_back(v);
  bstLevelList(v->left, levelsList, h+1);
  bstLevelList(v->right, levelsList, h+1);
};

int main (void) {
  int  unbalanced[] = {4,2,-1,-1,1,3,5,7,-1,-1,-1,-1,6,-1,-1};
  BstLink bst = 0;
  buildBst(bst, unbalanced);
  vector<list<BstLink>> levelsList;
  bstLevelList(bst, levelsList, 0);
  dumpBstLevelList(levelsList);
}


#if 0
#include <algorithm>
#include <iostream>

using std::cout;
using std::max;

struct BstNode {
  int value;
  BstNode *left, *right;
  BstNode (int x): value(x), left(0), right(0){}
};

typedef BstNode* BstLink;

int getHeight (BstLink v) {
  if (!v) return 0;
  return 1 + max(getHeight(v->left), getHeight(v->right));
}

struct Node {
  BstLink item;
  Node *next;
  Node (BstLink v): item(v), next(0){}
};

typedef Node* Link;

void insert (Link& n, BstLink v) {
  Link t = new Node(v);
  t->next = n;
  n = t;
};

void dumpBstLevelList (Link l[], int levels) {
  for (int i = 0; i < levels; ++i) {
    cout << "Level " << i << ": ";
    for (Link t = l[i]; t != 0; t = t->next) {
      cout << t->item->value << " ";
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

void bstLevelList (BstLink v, Link l[], int h) {
  if (!v) return;
  insert(l[h], v);
  bstLevelList(v->left, l, h+1);
  bstLevelList(v->right, l, h+1);
};

void bstLevelList (BstLink v) {
  int h = getHeight(v);
  Link* levelList = new Link[h];
  bstLevelList(v, levelList, 0);
  dumpBstLevelList(levelList, h);
}



int main (void) {
  int  unbalanced[] = {4,2,-1,-1,1,3,5,7,-1,-1,-1,-1,6,-1,-1};
  BstLink bst = 0;
  buildBst(bst, unbalanced);
  bstLevelList(bst);
}

#endif


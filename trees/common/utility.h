#include <iostream>

using std::cout;

struct BtNode {
  int value;
  BtNode *left, *right, *parent;
  BtNode (int x): value(x), left(0), right(0), parent(0){}
};

typedef BtNode* Link;

static int idx;

void buildBt (Link& v, Link p, int cmd[]) {
  
  int t = cmd[idx++];
  if (t < 0) {
    v = 0;
  }
  else {
    v = new BtNode(t);
    v->parent = p;
    buildBt(v->left, v, cmd);
    buildBt(v->right, v, cmd);
  }
}

void buildBtree (Link& v, int cmd[]) {
  idx = 0;
  buildBt(v, 0, cmd);
}

void dump (std::ostream& out, Link t, int h) {

  if (t == 0) {
    for (int i = 0; i < h; ++i) {
      out << " ";
    }
    out << "*" << std::endl;
    return;
  }

  dump (out, t->right, h+1);
  for (int i = 0; i < h; ++i) {
      out << " ";
  }
  out << t->value << std::endl;
  dump (out, t->left, h+1);
}

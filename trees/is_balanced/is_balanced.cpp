#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::vector;

class BinaryTree {

  struct Node {
    int value;
    Node *left, *right;
    Node (int x): value(x), left(0), right(0){}
  };
  
  typedef Node* Link;
  static int idx;
  Link root;
  int isBalancedR (Link v) const;
  void build (Link& v, int cmd[]);
  void dump (std::ostream& out, Link t, int h) const;

public:
  BinaryTree (int cmd[]);
  bool isBalanced (void) const;
  friend std::ostream& operator<< (std::ostream& out, const BinaryTree& bt);
};

int BinaryTree::idx = 0;

BinaryTree::BinaryTree (int cmd[]) {
  idx = 0;
  build(root, cmd);
}

void BinaryTree::build (Link& v, int cmd[]) {
  int t = cmd[idx++];
    if (t < 0) {
      v = 0;
    }
    else {
      v = new Node(t);
      build(v->left, cmd);
      build(v->right, cmd);
    }
}

int BinaryTree::isBalancedR (Link v) const{
  if (!v) return 0;
  int hl = isBalancedR(v->left);
  int hr = isBalancedR(v->right);
  if (hr < 0 || hl < 0) return -1;
  if (std::abs(hl-hr)>1) return -1;
  else return 1 + std::max(hl, hr);
}

bool BinaryTree::isBalanced (void) const{
  if (isBalancedR(root) < 0) return false;
  else return true;
}

std::ostream& operator<< (std::ostream& out, const BinaryTree& bt) {
  bt.dump (out, bt.root, 0);
  return out;
}

void BinaryTree::dump (std::ostream& out, Link t, int h) const {

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

int main (void) {
  int  unbalanced[] = {4,2,-1,-1,1,3,5,7,-1,-1,-1,-1,6,-1,-1};
  BinaryTree unbal(unbalanced);
  cout << unbal;
  cout << unbal.isBalanced();

  int  balanced[] = {4,2,1,-1,-1,3,-1,-1,6,5,-1,-1,7,-1,-1};
  BinaryTree bal(balanced);
  cout << bal;
  cout << bal.isBalanced();
}



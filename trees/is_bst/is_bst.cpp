#include <climits>
#include <iostream>

using std::cout;

class BinaryTree {
  struct Node {
    int value;
    Node *left, *right;
    Node (int x): value(x), left(0), right(0){}
  };

  typedef Node* Link;
  Link root;
  bool checkBstNode (Link v, int min, int max) const;
  bool isBst (Link v, int min, int max) const;
  void dump (std::ostream& out, Link t, int h) const;
  void build (Link& v, int cmd[], int& idx);

public:
  BinaryTree (int cmd[]);
  bool isBst (void) const;

  friend std::ostream& operator<< (std::ostream& out, const BinaryTree& bt);
  
};

BinaryTree::BinaryTree (int cmd[]): root(0) {
  int idx = 0;
  build(root, cmd, idx);
}

void BinaryTree::build (Link& v, int cmd[], int& idx) {
  int t = cmd[idx++];
  if (t < 0) {
    v = 0;
  }
  else {
    v = new Node(t);
    build(v->left, cmd, idx);
    build(v->right, cmd, idx);
  }
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

bool  BinaryTree::checkBstNode (Link v, int min, int max) const{
  if (v->value >= min && v->value < max) return true;
  return false;
}

bool  BinaryTree::isBst (Link v, int min, int max) const{
  if (!v) return true;
  if(!checkBstNode(v, min, max)) return false;
  return (isBst(v->left, min, v->value) && isBst(v->right, v->value, max));
}

bool  BinaryTree::isBst (void) const{
  int min_threshold = INT_MIN;
  int max_threshold = INT_MAX;
  return isBst(root, min_threshold, max_threshold);
}

int main (void) {
  int  bst_tree[] = {4,2,1,-1,-1,8,-1,-1,6,5,-1,-1,7,-1,-1};
  BinaryTree bal(bst_tree);
  cout << bal << "\n";
  cout << bal.isBst() << "\n";

  int  not_bst_tree[] = {4,2,1,-1,-1,3,-1,-1,6,5,-1,-1,7,-1,-1};
  BinaryTree not_bst(not_bst_tree);
  cout << not_bst << "\n";
  cout << not_bst.isBst();
  
}

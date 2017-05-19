#include <iostream>

using std::cout;

class Bst {
  struct Node {
    int key;
    Node *left, *right, *parent;
    Node (int k): key(k), left(0), right(0), parent(0){}
  };
  

  Node* root;

  void buildBst (Node*& v, Node* p, int cmd[]);
  void dump (std::ostream& out, Node*  t, int h) const;
public:
  typedef Node* Link;
  Bst (int cmd[]) { buildBst(root, 0, cmd); }
  Link findSuccessor (Link v);
  Link search (int k);
  friend std::ostream& operator<< (std::ostream& out, const Bst& bt);
};

void Bst::buildBst (Link& v, Link p, int cmd[]) {
  static int idx = 0;
  int t = cmd[idx++];
  if (t < 0) {
    v = 0;
  }
  else {
    v = new Node(t);
    v->parent = p;
    buildBst(v->left, v, cmd);
    buildBst(v->right, v, cmd);
  }
}

Bst::Link Bst::search (int k) {
  Link v = root;
  while (v) {
    if (v->key == k) return v;
    if (k < v->key) v = v->left;
    else v = v->right;
  }
  return 0;
}

Bst::Link Bst::findSuccessor (Link v) {
  if (!v) return 0;
  
  if (v->right) {
    v = v->right;
    while (v->left) v = v->left;
    return v;
  }

  int v_key = v->key;
  while (v->parent) {
    if(v->parent->key > v_key) return v->parent;
    v = v->parent;
  }
  return 0;
}

std::ostream& operator<< (std::ostream& out, const Bst& bt) {
  bt.dump (out, bt.root, 0);
  return out;
}

void Bst::dump (std::ostream& out, Link t, int h) const {

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
  out << t->key << std::endl;
  dump (out, t->left, h+1);
}

int main (void) {
  int  bst_tree[] = {4,2,1,-1,-1,3,-1,-1,6,5,-1,-1,7,-1,-1};
  Bst bst(bst_tree);
  cout << bst << "\n";
  Bst::Link n, succ;

  //test internal node
  n = bst.search(4);
  cout << n->key;
  succ = bst.findSuccessor(n);
  if(succ) cout << succ->key;
  else cout << "no succ";

  //test leaf node
  n = bst.search(5);
  cout << n->key;
  succ = bst.findSuccessor(n);
  if(succ) cout << succ->key;
  else cout << "no succ";

  //test bigger node
  n = bst.search(7);
  cout << n->key;
  succ = bst.findSuccessor(n);
  if(succ) cout << succ->key;
  else cout << "no succ";
}

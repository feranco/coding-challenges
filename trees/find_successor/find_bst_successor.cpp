// algorithm to find the successor of a node v of a binary search tree t
// i.e. find theinorder successor

// assumption: 
// 1) tree is binary search tree
// 2) each node has an integer value with ptr to the left and right children and to the parent

#include "../common/utility.h"

Link search (Link root, int k) {
  Link v = root;
  while (v) {
    if (v->value == k) return v;
    if (k < v->value) v = v->left;
    else v = v->right;
  }
  return 0;
}

Link findSuccessor (Link v) {
  if (!v) return 0;

  //if v has a right child r, the successor is the
  //leftmost child of r
  if (v->right) {
    Link r = v->right;
    while (r->left) r = r->left;
    return r;
  }

  //otherwise the successor is the parent of the first ancestor which is
  //a left child
  Link p = v->parent;
  Link t = v;
  while (p) {
    if(p->left == t) return p;
    t = p;
    p = p->parent;
  }
  //v is the rightmost leaf of the tree
  return 0;
}

int main (void) {
  int  tree_val[] = {4,2,1,-1,-1,3,-1,-1,6,5,-1,-1,7,-1,-1};
  Link tree = 0;
  buildBtree(tree,  tree_val);
  dump(cout, tree, 0);
  Link n, succ;

  //test internal node
  n = search(tree,4);
  cout << n->value;
  succ = findSuccessor(n);
  if(succ) cout << succ->value;
  else cout << "no succ";

  //test leaf node
  n = search(tree,5);
  cout << n->value;
  succ = findSuccessor(n);
  if(succ) cout << succ->value;
  else cout << "no succ";

  //test bigger node
  n = search(tree,7);
  cout << n->value;
  succ = findSuccessor(n);
  if(succ) cout << succ->value;
  else cout << "no succ";
}

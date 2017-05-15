#include <iostream>

using std::cout;

//BST node
struct Node {
  int value;
  Node *left, *right;
  Node (int x): value(x), left(0), right(0){}
};

typedef Node* Link;

void buildBST (Link& v, int a[], int l, int r) {
  if (l > r)  return;
  int m = (l+r) / 2;
  v = new Node(a[m]);
  buildBST(v->left, a, l, m-1);
  buildBST(v->right, a, m+1, r);
}

void dump (Link t, int h) {

  if (t == 0) {
    for (int i = 0; i < h; ++i) {
      cout << "   ";
    }
    cout << "*" << std::endl;
    return;
  }

  dump (t->right, h+1);
  for (int i = 0; i < h; ++i) {
      cout << "   ";
  }
  cout << t->value << std::endl;
  dump (t->left, h+1);
}

int main(void) {
  Link bst = 0;
  int a[] = {1, 3, 6, 8, 10, 13, 15, 17, 18, 20, 22, 23};
  buildBST(bst, a, 0, 11);
  dump(bst, 0);
}


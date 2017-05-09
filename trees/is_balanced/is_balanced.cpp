#include <iostream>
#include <vector>
#include <utility>

using std::cout;

class BinaryTree {

  struct Node {
    int value;
    Node *left, *right;
    Node (int x): value(x), left(0), right(0){}
  };
  
  typedef Node* Link;
  Link root;
  bool isBalanced (Link v, int& h);

public:
  BinaryTree (vector<pair<char,int> > cmd);
  bool isBalanced (void) const;
};

BinaryTree (vector<pair<char,int> > cmd) {
  for (const auto& x : cmd) {
    if (x.first == 'l')
  }
}

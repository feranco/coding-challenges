#include <memory>
#include <iostream>

using std::unique_ptr;

template <typename T>
struct BstNode {
  T data;
  BstNode<T>* parent;
  unique_ptr<BstNode<T>> left, right;
  BstNode (T data, BstNode<T>* p = nullptr,  BstNode<T>* l = nullptr,  BstNode<T>* r = nullptr) {
    this->data = data;
    parent = p;
    left.reset(l); 
    right.reset(r);
    } 
};

//print (sub)tree
const int spaces = 2;
template <typename T>
void dump(const unique_ptr<BstNode<T>>& root, int h)  {
  //dump external node
  if (root == 0) {
    for (int i = 0; i < h; ++i) std::cout << "  ";
    std::cout << '*' << std::endl;
    return;
  }

  dump(root->right, h + spaces);
  
  //dump internal node
  for (int i = 0; i < h; ++i) {
    std::cout << "  ";
  }
  std::cout << root->data << std::endl;
  
  dump(root->left, h + spaces);
}

/*
template <typename T>
struct BstNode {
  T data;
  BstNode<T>* parent;
  unique_ptr<BstNode<T>> left, right;
  BstNode (T data, BstNode<T>* p = nullptr, unique_ptr<BstNode> l = nullptr, unique_ptr<BstNode> r = nullptr) {
    this->data = data;
    parent = p;
    l = std::move(l); 
    r = std::move(r);
  } 
};
*/

unique_ptr<BstNode<int>> buildTestBst (void) {
  unique_ptr<BstNode<int>> root(new BstNode<int>(19));
  root->left.reset(new BstNode<int>(7,root.get()));
  root->left->left.reset(new BstNode<int>(3,root->left.get()));
  root->left->left->left.reset(new BstNode<int>(2,root->left->left.get()));
  root->left->left->right.reset(new BstNode<int>(5,root->left->left.get()));
  root->left->right.reset(new BstNode<int>(11,root->left.get()));
  root->left->right->right.reset(new BstNode<int>(17,root->left->right.get()));
  root->left->right->right->left.reset(new BstNode<int>(13,root->left->right->right.get()));
  
  root->right.reset(new BstNode<int>(43,root.get()));
  root->right->left.reset(new BstNode<int>(23,root->right.get()));
  root->right->left->right.reset(new BstNode<int>(37,root->right->left.get()));
  root->right->left->right->left.reset(new BstNode<int>(29,root->right->left->right.get()));
  root->right->left->right->left->right.reset(new BstNode<int>(31,root->right->left->right->left.get()));
  root->right->left->right->right.reset(new BstNode<int>(41,root->right->left->right.get()));
  root->right->right.reset(new BstNode<int>(47,root->right.get()));
  root->right->right->right.reset(new BstNode<int>(53,root->right->right.get()));
  return root;
}
/*
unique_ptr<BtNode<int>> buildSymmetricBtree (void) {
  unique_ptr<BtNode<int>> root(new BtNode<int>(314));
  root->left.reset(new BtNode<int>(6,root.get()));
  root->left->left.reset(new BtNode<int>(271,root->left.get()));
  root->left->right.reset(new BtNode<int>(2,root->left.get()));
  root->left->right->right.reset(new BtNode<int>(3,root->left->right.get()));
  
  root->right.reset(new BtNode<int>(6,root.get()));
  root->right->left.reset(new BtNode<int>(2,root->right.get()));
  root->right->right.reset(new BtNode<int>(271,root->right.get()));
  //root->right->right->left.reset(new BtNode<int>(271,root->right.get()));
  root->right->left->left.reset(new BtNode<int>(3,root->right->right.get()));
  return root;
}


unique_ptr<BtNode<char>> buildCharBtree (void) {
  unique_ptr<BtNode<char>> root(new BtNode<char>('H'));
  root->left.reset(new BtNode<char>('B', root.get()));
  root->left->left.reset(new BtNode<char>('F',root->left.get()));
  root->left->right.reset(new BtNode<char>('E',root->left.get()));
  root->left->right->left.reset(new BtNode<char>('A',root->left->right.get()));
    
  root->right.reset(new BtNode<char>('C', root.get()));
  root->right->right.reset(new BtNode<char>('D', root->right.get()));
  root->right->right->right.reset(new BtNode<char>('G', root->right->right.get()));
  root->right->right->right->left.reset(new BtNode<char>('I', root->right->right->right.get()));
  return root;
}
*/

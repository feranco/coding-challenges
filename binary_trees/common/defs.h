#include <memory>

using std::unique_ptr;

template <typename T>
struct BtNode {
  T data;
  unique_ptr<BtNode<T>> left, right;
  BtNode<T>* parent;
  BtNode (T data, BtNode<T>* p = nullptr, unique_ptr<BtNode> l = nullptr, unique_ptr<BtNode> r = nullptr) {
    this->data = data; 
    l = std::move(l); 
    r = std::move(r);
  } 
};

unique_ptr<BtNode<int>> buildTestBtree (void) {
  unique_ptr<BtNode<int>> root(new BtNode<int>(314));
  root->left.reset(new BtNode<int>(6,root.get()));
  root->left->left.reset(new BtNode<int>(271,root->left.get()));
  root->left->left->left.reset(new BtNode<int>(28,root->left->left.get()));
  root->left->left->right.reset(new BtNode<int>(0,root->left->left.get()));
  root->left->right.reset(new BtNode<int>(5611,root->left.get()));
  root->left->right->right.reset(new BtNode<int>(31,root->left->right.get()));
  root->left->right->right->left.reset(new BtNode<int>(17,root->left->right->right.get()));
  
  root->right.reset(new BtNode<int>(66,root.get()));
  root->right->left.reset(new BtNode<int>(26,root->right.get()));
  root->right->left->right.reset(new BtNode<int>(16,root->right->left.get()));
  root->right->left->right->left.reset(new BtNode<int>(401,root->right->left->right.get()));
  root->right->left->right->left->right.reset(new BtNode<int>(641,root->right->left->right->left.get()));
  root->right->left->right->right.reset(new BtNode<int>(257,root->right->left->right.get()));
  root->right->right.reset(new BtNode<int>(271,root->right.get()));
  root->right->right->right.reset(new BtNode<int>(28,root->right->right.get()));
  return root;
}

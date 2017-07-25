#include <memory>

using std::unique_ptr;

template <typename T>
struct BtNode {
  T data;
  unique_ptr<BtNode<T>> left, right;
  BtNode (T data, unique_ptr<BtNode> left = nullptr, unique_ptr<BtNode> right = nullptr) {
    this->data = data; 
    this->left = std::move(left); 
    this->right = std::move(right);
  } 
};

unique_ptr<BtNode<int>> buildTestBtree (void) {
  unique_ptr<BtNode<int>> root(new BtNode<int>(314));
  root->left.reset(new BtNode<int>(6));
  root->left->left.reset(new BtNode<int>(271));
  root->left->left->left.reset(new BtNode<int>(28));
  root->left->left->right.reset(new BtNode<int>(0));
  root->left->right.reset(new BtNode<int>(561));
  root->left->right->right.reset(new BtNode<int>(3));
  root->left->right->right->left.reset(new BtNode<int>(17));
  
  root->right.reset(new BtNode<int>(6));
  root->right->left.reset(new BtNode<int>(2));
  root->right->left->right.reset(new BtNode<int>(1));
  root->right->left->right->left.reset(new BtNode<int>(401));
  root->right->left->right->left->right.reset(new BtNode<int>(641));
  root->right->left->right->right.reset(new BtNode<int>(257));
  root->right->right.reset(new BtNode<int>(271));
  root->right->right->right.reset(new BtNode<int>(28));
  return root;
}

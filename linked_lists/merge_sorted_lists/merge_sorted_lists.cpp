//algorithm to merge two sorted list 
//Assumptions:
//1) lists contain integer
//O(n) time where n sizeis the position of the sublist end O(1) space
#include <iostream>

using std::make_shared;
using std::shared_ptr;

struct Node {
  int value;
  shared_ptr<Node> next;
  Node (int value) {this->value = value; next = nullptr;}
};

void appendToMerged (shared_ptr<Node>* merged, shared_ptr<Node>* new_node) {
  (*merged)->next = *new_node;
  *new_node = (*new_node)->next;
  *merged = (*merged)->next;
}

shared_ptr<Node> merge (shared_ptr<Node> l1, shared_ptr<Node> l2) {
  auto merged_list = make_shared<Node>(0);
  auto current = merged_list;

  #if 0
  //code duplication avoided with appendToMerged
  while (l1 && l2) {
    if (l1->value < l2->value) {
      current->next = l1;
      l1 = l1->next;
    }
    else {
      current->next = l2;
      l2 = l2->next;
    }
  }
  #endif
  
  while (l1 && l2) {
    if (l1->value < l2->value) appendToMerged(&current, &l1);
    else appendToMerged(&current, &l2);
  }

  current->next = (l1 == nullptr) ? l2 : l1;

 
  return merged_list->next;
}

int main (void) {
  shared_ptr<Node> l1, l2;
  l1 = make_shared<Node>(2);
  l1->next = make_shared<Node>(5);
  l1->next->next = make_shared<Node>(7);

  l2 = make_shared<Node>(3);
  l2->next = make_shared<Node>(11);

  auto m = merge(l1, l2);

  while (m != nullptr) {
    std::cout << m->value << " ";
    m = m->next;
  }
}


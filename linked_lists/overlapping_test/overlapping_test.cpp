//algorithm to detect if two list overlaps
//Assumptions:
//1) lists contain integer
//O(n) time where n size of the sublist O(1) space

#include <iostream>
#include <memory>

using std::make_shared;
using std::shared_ptr;

template <typename T>
struct Node {
  T value;
  shared_ptr<Node<T>> next;
  Node (T value) {this->value = value; next = nullptr;}
};

void advance (int k, shared_ptr<Node<int>>* l) {
  while (k--) *l = (*l)->next;
}

int length (shared_ptr<Node<int>>* l) {
  int length = 0;
  while ((*l)->next) {
    (*l) = (*l)->next;
    length++;
  }
  return length;
}

shared_ptr<Node<int>> areOverlapped (const shared_ptr<Node<int>>& l1, const shared_ptr<Node<int>>& l2) {
  int length_l1 = 0, length_l2 = 0;

  auto iter_l1 = l1, iter_l2 = l2;

  length_l1 = length(&iter_l1);
  length_l2 = length(&iter_l2);
  
  if (iter_l1 != iter_l2) return nullptr;

  iter_l1 = l1, iter_l2 = l2;
    
  advance(abs(length_l1-length_l2), length_l1 > length_l2 ? &iter_l1 : &iter_l2);

  while (iter_l1 != iter_l2) {
    iter_l1 = iter_l1->next;
    iter_l2 = iter_l2->next;
  }

  return iter_l1;


}

int main (void) {
  shared_ptr<Node<int>> l1, l2;
  l1 = make_shared<Node<int>>(9);
  l1->next = make_shared<Node<int>>(31);
  l1->next->next = make_shared<Node<int>>(11);
  l1->next->next = make_shared<Node<int>>(7);
  l1->next->next->next = make_shared<Node<int>>(5);
  l1->next->next->next->next = make_shared<Node<int>>(2);

  l2 = make_shared<Node<int>>(4);
  l2->next = make_shared<Node<int>>(8);
  l2->next->next = l1->next->next->next;

  auto m = areOverlapped(l1, l2);
  std::cout << m->value;
}


#if 0
shared_ptr<Node<int>> areOverlapped (const shared_ptr<Node<int>>& l1, const shared_ptr<Node<int>>& l2) {
  int length_l1 = 0, length_l2 = 0;

  auto iter_l1 = l1, iter_l2 = l2;

  while (iter_l1->next) {
    iter_l1 = iter_l1->next;
    length_l1++;
  }

  while (iter_l2->next) {
    iter_l2 = iter_l2->next;
    length_l2++;
  }
  
  if (iter_l1 == iter_l2) {
    iter_l1 = l1, iter_l2 = l2;
    if (length_l1 > length_l2) {
      while (length_l1-- > length_l2) iter_l1 = iter_l1->next;
    }
    else if (length_l2 > length_l1) {
      while (length_l2-- > length_l1) iter_l2 = iter_l2->next;
    }

    while (iter_l1 != iter_l2) {
      iter_l1 = iter_l1->next;
      iter_l2 = iter_l2->next;
    }

    return iter_l1;
  }
  
  return nullptr;

}
#endif

//insertion sort implementation for linked list
//O(n^2)
//the code can be simplified using a sorted list
//this list is empty at the beginning, then at each step a node from the original list
//is moved in the right position in the sorted list

#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct Node {
  T value;
  shared_ptr<Node<T>> next;
  Node (T value) {this->value = value; next = nullptr;}
};

 
shared_ptr<Node<int>> insertionSortList(shared_ptr<Node<int>>& a) {
  Node<int> dummy(0);
  dummy.next = a;
  shared_ptr<Node<int>>  current = a;
    
  while (current->next != NULL) {
    shared_ptr<Node<int>> iterator = make_shared<Node<int>>(dummy);
    while (iterator->next->value <= current->next->value && iterator != current) {
      iterator = iterator->next;
    }
    //insert current after iterator or go to next element since current was already in place
    if (iterator->next != current->next) {
      shared_ptr<Node<int>> next = current->next->next;
      current->next->next = iterator->next;
      iterator->next = current->next;
      current->next = next;
    }
    else current = current->next;
  }
  return dummy.next;
}

int main (void) {
  shared_ptr<Node<int>> l1, l2;
  l1 = make_shared<Node<int>>(1);
  l1->next = make_shared<Node<int>>(4);
  l1->next->next = make_shared<Node<int>>(3);
  l1->next->next->next = make_shared<Node<int>>(2);
  auto m = insertionSortList(l1);
  while (m != nullptr) {
    cout << m->value << " ";
    m = m->next;
  }
}

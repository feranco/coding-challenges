//algorithm to reverse a sublist within a list given
//the start and end position of the sublist
//Assumptions:
//1) list contain integer
//2) position in the list are numbered from 1 to n
//O(n) time where n size of the sublist O(1) space

#include <iostream>

using std::make_shared;
using std::shared_ptr;

struct Node {
  int value;
  shared_ptr<Node> next;
  Node (int value) {this->value = value; next = nullptr;}
};


void reverse (shared_ptr<Node>* head, int start, int end) {
    if (!*head || end <= start) return;  //check inputs validity
    
    auto dummy_head = make_shared<Node>(0);
    dummy_head->next = *head;
    auto sublist_head = dummy_head;
    
    for (int i = 1; i < start; ++i) sublist_head = sublist_head->next;
    
    auto sublist_iter = sublist_head->next;

    //always insert in front of dummy list
    for (int i = start; i < end; ++i) {
      auto tmp = sublist_iter->next;
      sublist_iter->next = tmp->next;
      
      tmp->next = sublist_head->next;
      sublist_head->next = tmp;
    }

    *head = dummy_head->next;
}

int main (void) {
  shared_ptr<Node> list;
  list = make_shared<Node>(11);
  list->next = make_shared<Node>(3);
  list->next->next = make_shared<Node>(5);
  list->next->next->next = make_shared<Node>(7);
  list->next->next->next->next = make_shared<Node>(2);


  reverse(&list, 2, 4);
  
  while (list != nullptr) {
    std::cout << list->value << " ";
    list = list->next;
    }
}  
 

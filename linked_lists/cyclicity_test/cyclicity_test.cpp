//algorithm to detect if a list contain cycles
//Assumptions:
//1) list contain integer
//O(n) time where n size of the sublist O(1) space

#include <iostream>

using std::make_shared;
using std::shared_ptr;

struct Node {
  int value;
  shared_ptr<Node> next;
  Node (int value) {this->value = value; next = nullptr;}
};

//only bool test
bool isCyclic (const shared_ptr<Node>& list) {
  if (!list) return false;
	
  auto slow = list;
  auto fast = list->next;
	
  while (fast && fast->next) {
    if (slow == fast) return true;
    slow = slow->next;
    fast = fast->next->next;
  }
  return false;
}

#if 0
//return ptr to start cycle or null
shared_ptr<Node> isCyclic (const shared_ptr<Node>& list) {
  if (!list) return nullptr;
    
  auto slow = list;
  auto fast = list->next;
    
  while (fast && fast->next) {
    if (slow == fast) {
      int cycle_length = 0;
      do {
	cycle_length++;
	slow = slow->next;
      }while(slow != fast);
            
      slow = list, fast = list->next;
      while(cycle_length--)  fast = fast->next;
      while(fast != slow) {
	fast = fast->next;
	slow = slow->next;
      }
      return slow;
    }
    slow = slow->next;
    fast = fast->next->next;
  } 
 
  return nullptr;
}
#endif

int main (void) {
  shared_ptr<Node> list;
  list = make_shared<Node>(11);
  list->next = make_shared<Node>(3);
  list->next->next = make_shared<Node>(5);
  list->next->next->next = make_shared<Node>(7);
  list->next->next->next->next = make_shared<Node>(2);
  //list->next->next->next->next->next = list->next;

  std::cout <<isCyclic(list);
} 

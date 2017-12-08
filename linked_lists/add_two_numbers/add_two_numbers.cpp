/*
 You are given two non-empty linked lists representing two non-negative integers. 
 The digits are stored in reverse order and each of their nodes contain a single digit. 
 Add the two numbers and return it as a linked list.
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 https://leetcode.com/problems/add-two-numbers/description/
*/

#include <iostream>
#include <memory>

using namespace std;

struct ListNode {
  int value;
  shared_ptr<ListNode> next;
  ListNode (int x) : value(x), next(nullptr) {}
};

//O(n) time where n = max_length(l1,l2), O(n) space
shared_ptr<ListNode> addTwoNumbers(shared_ptr<ListNode> l1, shared_ptr<ListNode> l2) {
  
  shared_ptr<ListNode> result = make_shared<ListNode>(0);
  shared_ptr<ListNode> it(result);
  int digit = 0, carry = 0;

  while (l1 && l2) {
    digit = (l1->value + l2->value + carry) % 10;
    carry = (l1->value + l2->value + carry) / 10;
    it->next = make_shared<ListNode>(digit);
    
    it = it->next;
    l1 = l1->next;
    l2 = l2->next;
  }

  if (l1)
    it->next = addTwoNumbers(l1,make_shared<ListNode>(carry));
  else if (l2)
    it->next = addTwoNumbers(l2,make_shared<ListNode>(carry));
  else if (carry){
    while(it->next) it = it->next;
    it->next = make_shared<ListNode>(carry);
  }

  return result->next;
}

int main (void) {
  shared_ptr<ListNode> l1, l2;
  l1 = make_shared<ListNode>(2);
  l1->next = make_shared<ListNode>(4);
  l1->next->next = make_shared<ListNode>(3);

  l2 = make_shared<ListNode>(5);
  l2->next = make_shared<ListNode>(6);
  l2->next->next = make_shared<ListNode>(4);

  auto sum = addTwoNumbers(l1,l2);

  
  if (sum->value == 7 && sum->next->value == 0 &&
      sum->next->next->value == 8) {
    cout << "Correct!" << endl;
  }
  else {
    cout << "Wrong!" << endl;
  }
  
  
}

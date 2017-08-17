//algorithms to sort a list
//first solution: selection sort O(n^2) always
//second solution: insertion sort O(n^2) average and worst, O(n) best (already sorted)
//third solution: merge sort O(nlogn)

#include <memory>
#include <iostream>

using namespace std;

struct Node {
  int value;
  shared_ptr<Node> next;
  Node(int value, shared_ptr<Node> next = nullptr) { this->value = value; this->next = next; }
};


shared_ptr<Node> SelectionSort(shared_ptr<Node>& head) {
  shared_ptr<Node> dummy_head = make_shared<Node>(0, head);
  shared_ptr<Node> sorted_head = make_shared<Node>(0);
  shared_ptr<Node> sorted_tail = sorted_head;

  while (dummy_head->next != nullptr) {
    //find the pointer to the minimum element remained in the list 
    shared_ptr<Node> min_ptr = dummy_head;
    for (auto it = dummy_head->next; it->next != nullptr; it = it->next) {
      if (it->next->value < min_ptr->next->value) min_ptr = it;
    }

    auto min = min_ptr->next;
    min_ptr->next = min_ptr->next->next;  //remove the minumum element from the list

    min->next = nullptr;
    sorted_tail->next = min;
    sorted_tail = sorted_tail->next;
  }
  return sorted_head->next;
}

shared_ptr<Node> InsertionSort(shared_ptr<Node>& head) {
  shared_ptr<Node> ptrHead = make_shared<Node>(0, head);
  shared_ptr<Node> it = head;

  while (it != nullptr && it->next != nullptr) {
    if (it->next->value < it->value) {
      auto to_insert = it->next;
      it->next = it->next->next;
      auto sorted_it = ptrHead;
      while (sorted_it->next->value < to_insert->value) sorted_it = sorted_it->next;
      to_insert->next = sorted_it->next;
      sorted_it->next = to_insert;
    }
    else{ it = it->next;}
		
  }
  return ptrHead->next;
}

shared_ptr<Node> Merge(shared_ptr<Node>& left, shared_ptr<Node>& right) {
  shared_ptr<Node> dummy_head = make_shared<Node>(0);
  auto it = dummy_head;

  while (left != nullptr && right != nullptr) {
    if (left->value < right->value) {
      it->next = left;
      left = left->next;
    }
    else {
      it->next = right;
      right = right->next;
    }
    it = it->next;
    it->next = nullptr;
  }
  it->next = (!left) ? right : left;
  return dummy_head->next;
}

shared_ptr<Node> MergeSort(shared_ptr<Node>& head) {

  if (!head) return nullptr; //empty list
  if (!head->next) return head;

  auto slow = head, fast = head->next;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  //separate the list on the left from the one on the right
  auto left = head;
  auto right = slow->next;
  slow->next = nullptr;
  left = MergeSort(left);
  right = MergeSort(right);
  return Merge(left, right);

}


int main(void) {
  
  auto print = [](shared_ptr<Node>& list) {while(list){ cout << list->value << " "; list = list->next;}};
  
  shared_ptr<Node> l1;
  l1 = make_shared<Node>(7);
  l1->next = make_shared<Node>(5);
  l1->next->next = make_shared<Node>(6);
  l1->next->next->next = make_shared<Node>(4);
  auto sorted = MergeSort(l1);
  print(sorted);

  shared_ptr<Node> l2;
  l2 = make_shared<Node>(7);
  l2->next = make_shared<Node>(5);
  l2->next->next = make_shared<Node>(6);
  l2->next->next->next = make_shared<Node>(4);
  auto sorted2 =InsertionSort(l1);
  print(sorted2);
  
}

//algorithm to sort a k_sorted_array
//Assumptions:
//1) each element of the array is far not more than k from its final position

#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::priority_queue;
using std::vector;

void sort (vector<int>* a_ptr, int k) {
  vector<int>& a = *a_ptr;
  auto cmp = [](int a, int b){return a > b;};
  priority_queue<int, vector<int>, decltype(cmp)> min_heap(a.begin(), a.begin()+k+1, cmp);
  auto r = a.begin(), w = a.begin()+k+1;

  while (!min_heap.empty()) {
    *iter = min_heap.top();
    min_heap.pop();
    ++iter;
    if (next != a.end()) {
      min_heap.push(*next);
      ++next;
    }
  }
}

int main (void) {
  vector<int> a{3, -1, 2, 6, 4, 5, 8};
  sort(&a, 2);
  for (int x : a) cout << x << " ";
}

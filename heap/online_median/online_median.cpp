//algorithm to find the median of a stream of number online

#include <queue>
#include <iostream>
#include <vector>

using std::priority_queue;
using std::istream;
using std::cin;
using std::cout;

void onlineMedian (istream& is) {
  //IMPORTANT: if priority_queue contains custom types or user-defined types with operator> or
  //operator< defined, it's possible declare the queue with functions less or greater as third arguments
  auto min_heap_cmp = [](double a, double b){return a > b;};
  priority_queue<double> max_heap;
  priority_queue<double, std::vector<double>, decltype(min_heap_cmp)> min_heap(min_heap_cmp);
  double current;
  is >> current;
  max_heap.push(current);
  cout << current;

  while (is >> current) {
    //insert the new element in the max heap or in the min heap
    //according to its value
    if (current <= max_heap.top()) max_heap.push(current);
    else min_heap.push(current);

    //optimization: the code below guarantees that max heap is always greater or equal to min heap
    //this avoid duplicated call to cout
    if (max_heap.size() > min_heap.size() + 1) {
      //if max heap size - min heap size is greater than 1, make their size equal -->print average
      min_heap.push(max_heap.top());
      max_heap.pop();
    }
    else if (min_heap.size() > max_heap.size()) {
      //if min heap size is greater than max heap size, make their size equal -->print average
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
    //otherwise max heap size  - min heap size is 1 -->print max top
    
    cout << (max_heap.size() > min_heap.size() ? max_heap.top() :
	    (min_heap.top() + max_heap.top()) * 0.5)  << "\n";

    /*
    //not optimized
    if (max_heap.size() > min_heap.size() + 1) {
      min_heap.push(max_heap.top());
      max_heap.pop();
      cout << (min_heap.top() + max_heap.top()) * 0.5;
    }
    else if (min_heap.size() > max_heap.size() + 1) {
      max_heap.push(min_heap.top());
      min_heap.pop();
      cout << (min_heap.top() + max_heap.top()) * 0.5;
    }
    else cout << ((max_heap.size() > min_heap.size()) ? max_heap.top() : min_heap.top());
    */   
  }
}

int main (void) {
  onlineMedian(std::cin);
}

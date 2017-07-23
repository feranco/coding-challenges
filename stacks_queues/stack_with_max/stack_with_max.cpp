//stack with max API implementation
//O(1) time O(n) space where n depends on the sequence of data
//pushed into the stack

#include <iostream>
#include <stack>
#include <utility>
#include <stdexcept>

using std::cout;
using std::pair;
using std::make_pair;
using std::stack;

template <typename T>
class Stack {
  stack<T> items;
  stack<pair<T,int>> max_cnt;
public:
  void push (T item) {   
    items.push(item);
    if (max_cnt.empty() || item > max_cnt.top().first) max_cnt.push(make_pair(item,1));  
    else  max_cnt.top().second++;
  }

  T pop (void) {
    if (items.empty()) throw std::length_error("Stack empty");
    auto res = items.top(); 
    items.pop();
    if (-- max_cnt.top().second == 0) {
      max_cnt.pop();
    }
    return res;
  }

  T max (void) {
    if (items.empty()) throw std::length_error("Stack empty");
    return  max_cnt.top().first;
  }
};

int main (void) {
  Stack<int> s;
  s.push(2);
  s.push(2);
  s.push(1);
  s.push(4);
  s.push(5);
  s.push(5);
  s.push(3);

  cout << s.max() << "\n";

  s.pop();
  s.pop();
  cout << s.max() << "\n";
  s.pop();
  cout << s.max() << "\n";
  s.pop();
  cout << s.max() << "\n";
  
}

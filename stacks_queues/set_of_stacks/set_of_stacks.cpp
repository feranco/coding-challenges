#include <stack>
#include <vector>
#include <iostream>
#include <stdexcept>

using std::vector;
using std::stack;
using std::cout;

class SetOfStacks {
  int max;
  int current;
  vector<stack<int> > stacks;

public:
  SetOfStacks (int threshold): max(threshold), current(0){stacks.push_back(stack<int>());}
  int pop (void);
  int popAt (int n);
  void push (int x);
  bool empty (void) {return stacks[0].empty();}
};

void SetOfStacks::push (int x) {
  if (stacks[current].size() == max) {
    stacks.push_back(stack<int>());
    current++;
  }
  stacks[current].push(x); 
}

int SetOfStacks::pop (void) {
  if (stacks[0].empty()) throw std::runtime_error("Stack empty!");
  int ret = stacks[current].top();
  stacks[current].pop();
  if(stacks[current].empty() && current > 0) {
    stacks.pop_back();
    current--;
  }
  return ret;
}

int SetOfStacks::popAt (int n) {
  if (n > current)  throw std::runtime_error("Wrong stack index!");
  if (n == current) return this->pop();
  int ret = stacks[n].top();
  stacks[n].pop();
  stack<int> tmp;
  for (int i = n; i < current; ++i) {
    while (!stacks[i+1].empty()) {
      tmp.push(stacks[i+1].top());
      stacks[i+1].pop();
    }
    stacks[i].push(tmp.top());
    tmp.pop();
    while (!tmp.empty()) {
      stacks[i+1].push(tmp.top());
      tmp.pop();
    }
  }
  
  if(stacks[current].empty() && current > 0) {
    stacks.pop_back();
    current--;
  }
  return ret;
}

int main (int argc, const char* argv[]) {
  SetOfStacks s(3);
  for (int i = 0; i < 9; ++i) s.push(i);
  for (int i = 0; i < 2; ++i) cout << s.pop() << "\n";
  cout << s.popAt(0) << "\n";
  while(!s.empty()) {
    cout << s.pop() << "\n";
  }
}

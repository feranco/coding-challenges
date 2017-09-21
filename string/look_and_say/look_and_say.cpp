//algorithm to generates the n-th element of a look and say sequence
//O(n2^n): n iterations, in the worst case the string is composed by
//all groups of 1 digit and the size of the new string is 2^n

#include <string>
#include <iostream>

using namespace std;

string nextElement (const string& sequence) {
  int it = 0;
  string next;
  while (it < sequence.size()) {
    int cnt = 0;
    //count the size of each group of consecutive equal digits
    for (int j = it; j < sequence.size() && sequence[j] == sequence[it]; ++j) ++cnt;
    //encode the size and the digit
    next.append(to_string(cnt));
    next.append(1,sequence[it]);
    it += cnt;
  }
  return next;
}

string lookAndSaySequence (int n) {
  string sequence{"1"};
  
  //generates incrementally the n-th element of the sequence
  for (int i = 1; i < n; ++i) {
    sequence = nextElement(sequence);
  }
  return sequence;
}

int main(void) {
  cout << lookAndSaySequence(6);
}

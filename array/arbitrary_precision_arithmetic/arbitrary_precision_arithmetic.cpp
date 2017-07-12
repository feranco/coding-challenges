#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<int> incrementByOne (vector<int> number) {
  int carry = 1;
  for (int i = number.size()-1; i >= 0; --i) {
    number[i] = (number[i] + carry) % 10;
    if (number[i] != 0) {carry = 0; break;}
  }
  if (carry) {
    number[0] = 0;
    number.insert(number.begin(), 1);
  }
  return number;
}

vector<int> incrementByOne (vector<int> number) {
  number.back()+ 1;
  for (int i = number.size()-1; i >= 0 && i; --i) {
    number[i] = (number[i] + carry) % 10;
    if (number[i] != 0) {carry = 0; break;}
  }
  if (carry) {
    number[0] = 0;
    number.insert(number.begin(), 1);
  }
  return number;
}

int main (void) {
  vector<int> n{{9,9,9}};
  n = incrementByOne(n);
  for (auto x : n) cout << x << " ";
}

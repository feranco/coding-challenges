//algorithm to add 1 to the array representation of a int
//O(n)
 
#include <vector>	
#include <iostream>

using  namespace std;

vector<int> plusOne(vector<int> &a) {
  int carriage = 1;
  for (int i = a.size() - 1; i >= 0; --i) {
    a[i] = a[i] + carriage;
    carriage = (a[i] == 10) ? 1 : 0;
    a[i] = (a[i] == 10) ? 0 : a[i];
  }

  int i = 0;
  vector<int> result;
  if (carriage == 1) result.emplace_back(1);
  else { while (i < a.size() && a[i] == 0) a[i++]; }
  while (i<a.size()) result.emplace_back(a[i++]);
  return result;
}

int main(void) {
  vector<int> input{9,9,9,9};
  auto r = plusOne(input);
  for (int x : r) cout << x;
}

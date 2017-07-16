//algorithm for arbitrary precision limit arithmetic simulated with array


#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

#if 0
//first tentative
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
#endif

//second tentative
//improvements:
//1) removed local variable carry
//2) removed break putting end of cycle in the for condition
vector<int> incrementByOne(vector<int> number) {
  number.back()++;

  for (int i = number.size() - 1; i > 0 && number[i] == 10; --i) {
    number[i] = 0;
    number[i - 1]++;
  }

  if (number[0] == 10) {
    number[0] = 0;  
    number.insert(number.begin(), 1);
  }
	
  return number;
}
#if 0
//first tentative
vector<int> multiply(vector<int> a, vector<int> b) {
  vector<vector<int>> grid(b.size(), vector<int>(a.size()+b.size()));
  vector<int> res(a.size() + b.size());
  int r, c, carry, offset;
  r = 0;
  offset = 1;
  for (int i = b.size()-1; i >= 0; --i) {
    c = a.size() + b.size() - offset;
    carry = 0;
    for (int j = a.size()-1; j >= 0; --j) {
      int val = (a[j] * b[i]) + carry;
      grid[r][c--] = val % 10;
      carry = val / 10;
    }
    grid[r++][c] = carry;
    offset++;
  }

  carry = 0;
  for (int i = a.size() + b.size() - 1; i >= 0; --i) {
    int val = 0;
    for (int j = b.size()-1; j >= 0; --j) {
      val += grid[j][i];
    }
    res[i] = (val + carry) % 10;
    carry = (val + carry) / 10;
  }

  return res;
}
#endif
//second tentative
//improvments:
//1) grid matrix can be removed putting results directly in res
vector<int> multiply(vector<int> a, vector<int> b) {
  vector<int> res(a.size() + b.size(),0);

  for (int i = b.size()-1; i >= 0; --i) {

    for (int j = a.size()-1; j >= 0; --j) {
      int val = a[j] * b[i];
      res[i+j+1] += val;
      res[i+j+1] %= 10;
      res[i+j] += val / 10;
    }
  }

  return res;
}

int main (void) {
  vector<int> n{{9,9,9}};
  n = incrementByOne(n);
  for (auto x : n) cout << x << " ";
  cout << "\n";

  vector<int> a{ { 3,4,5 } };
  vector<int> b{ { 9,9 } };
  vector<int> n2 = multiply(a, b);
  for (auto x : n2) cout << x << " ";
}

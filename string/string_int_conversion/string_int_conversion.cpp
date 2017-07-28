#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using std::string;

int stringToInt (const string& str) {
  int sign = str[0] == '-' ? -1 : 1;
  int x = 0;
  for (int i = sign < 0 ? 1 : 0; i < str.size(); ++i) {
    x = x * 10 + str[i] - '0';
  }
  return x * sign;
}

string intToString (int n) {
  int sign = n < 0 ? -1 : 1;
  string s;

  //do.. while instead of while
  //to manage the case n = 0 without a special condition
  do {
    s.push_back( '0' + abs(n % 10));
    n /= 10;
  }
  while(n);
  
  if (sign < 0) s.push_back('-');
  std::reverse(s.begin(), s.end());
  return s;
}

int main (void) {
  string n = "-123";
  std::cout << stringToInt(n);
  std::cout << intToString(-456);
}

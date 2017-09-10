//algorithm to convert a number from a base to another one
//Constraints:
//1) number is represented by a string
//2) bases are between 2 and 16
//O(n + nlogb2(size(s))) where n = log

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <iostream>

using namespace std;

string constructBase (int n, int b) {
  if (n == 0) return {};
  string result = constructBase(n/b,b);
  int  digit = n % b;
  result.push_back ((digit < 10) ? '0' + digit : 'A' + (digit-10));
  return result;
}

string baseConversion (const string& s, int b1, int b2) {
  
  bool is_negative = (s.front() == '-') ? true : false;
  int s_as_decimal = 0;
  
  //convert from b1 to base 10 with Horner's rule
  for (int i = (is_negative) ? 1 : 0; i < s.size(); ++i) {
    s_as_decimal *= b1;
    if (s[i] >= '0' && s[i] <= '9') s_as_decimal += s[i] - '0';
    else if (s[i] >= 'A' && s[i] <= 'F') s_as_decimal += s[i] - 'A';
    else throw std::invalid_argument("Invalid input number!");
  }

  return (!s_as_decimal) ? "0" : ((is_negative) ? "-" : string()) + constructBase (s_as_decimal, b2); 
}

#if 0
// not optimized: without horner's rule and with reverse of the result string
string baseConversion (const string& s, int b1, int b2) {
  
  bool is_negative = (s.front() == '-') ? true : false;
  int s_as_decimal = 0;
  
  int decimal = 0;
  int digit = 0;
  //convert from b1 to base 10
  for (int i = (is_negative) ? 1 : 0; i < s.size(); ++i) {
    if (s[i] >= '0' && s[i] <= '9') digit = s[i] - '0';
    else if (s[i] >= 'A' && s[i] <= 'F') digit = s[i] - 'A';
    else throw std::invalid_argument("Invalid input number!");
    decimal += digit * pow(b1,s.size()-1-i);
  }

  string result;
  while (s_as_decimal > 0) {
    digit = s_as_decimal % b2;
    s_as_decimal /= b2;
    char next = (digit < 10) ? '0' + digit : 'A' + (digit-10);
    result.push_back(next);
  }
  
  if (is_negative) result.push_back('-');

  reverse(result.begin(), result.end());
  return result; 
}
#endif

int main (int argc, char *argv[]) {
  
  string n(argv[1]);
  int b1 = atoi(argv[2]);
  int b2 = atoi(argv[3]);
  /*
  string n("615");
  int b1 = 7;
  int b2 = 13;
  */
  cout << baseConversion(n, b1, b2);
}

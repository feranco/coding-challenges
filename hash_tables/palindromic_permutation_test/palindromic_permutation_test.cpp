//algorithm to test if the characters of an input string
//can be used to permute the string
//O(n) time, O(d) space: n lenght of the input string
//d number of different char in the string

#include <iostream>
#include <unordered_map>
#include <string>

using std::string;
using std::unordered_map;

//code could be also implemented using an unordered_set
//and checking if the current character is in the set or not
//if in the set -->erase, otherwise insert
//the final size of the set shall be <=1
bool isPalindromicPermutable (const string& s) {
  unordered_map<char, int> char_frequency;
  for (char c : s) ++char_frequency[c];
  int odd = 0;
  for (auto f : char_frequency) {
    if (f.second % 2 != 0) ++odd;
    if (odd > 1) return false;
  }
  return true;
}

int main (void) {
  string s{"deified"};
  std::cout << isPalindromicPermutable(s);
}

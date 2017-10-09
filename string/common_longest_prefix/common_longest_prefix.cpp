//algorithm to find the longest common prefix of an array of strings
//O(m*n) where m is the minimum size string n the array and m is the number of string in the array
//O(m) space

#include <iostream>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &a) {
  string result;
  int min_size = a.front().size();
  for (const string& s : a) min(min_size,(int)s.size());
  for (int i = 0; i < min_size; ++i) {
    char c = a.front()[i];
    int  freq = 0;
    for (const string& s : a) {
      if (s[i] == c) ++freq;
    }
    if (freq == a.size()) result.push_back(c);
    else break;
  }
  return result;
}

int main (void) {
  vector<string> v{"abcdefgh","aefghijk","abcefgh"};
  cout << longestCommonPrefix(v);
}

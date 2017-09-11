//algorithm to verify if a string is palindromic
//Assumptions:
//1) do not care about not alphanumeric char
//2) do not car about upper/lower case
//O(n)

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool isPalindromic (const string& s) {
  int l = 0, r = s.size()-1;

  while (l < r) {
    while (!isalnum(s[l]) && (l < r)) ++l;
    while (!isalnum(s[r]) && (l < r)) --r;
    if (tolower(s[l++]) != tolower(s[r--])) return false;
  }

  return true;
}

int main (void) {
  string s("Able3 was I, ere I saw 3Elba!");
  cout << isPalindromic(s);
  /*
  //to lower applied to digit does nothing
  for_each(s.begin(), s.end(), [](char& c) {
      c = tolower(c);
    });
  cout << s;
  */
}

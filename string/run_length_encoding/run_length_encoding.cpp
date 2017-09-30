//algorithm to implement run length encoding
//O(n)
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

string decode (const string& s) {
  int idx = 0;
  string result;

  while (idx < s.size()) {
    //string frequency;
    int frequency = 0;
    while (isdigit(s[idx])) frequency = (frequency*10) + (s[idx++] - '0');//frequency.push_back(s[idx++]);
    result.append(frequency,s[idx++]);
    //result.append(stoi(frequency),s[idx++]);
  }
  return result;
}

string encode (const string& s) {
  int idx = 0;
  string result;

  while (idx < s.size()) {
    char c = s[idx++];
    int frequency = 1;
    while(idx < s.size() && s[idx] == c) {
      frequency++;
      idx++;
    }
    result += to_string(frequency) + c;
    //result.append(to_string(frequency));
    //result.push_back(c);
  }
  return result;
}

int main (void) {
  string test_encode{"aaaabcccaa"};
  cout << encode(test_encode) << endl;
  string test_decode{"3e4f2e"};
  cout << decode(test_decode) << endl;
}

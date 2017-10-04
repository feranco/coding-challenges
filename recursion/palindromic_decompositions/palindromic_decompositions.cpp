//algorithm to generate all palindromic decompositions of a string 
//O(n*2^n) when the string is a repetition of a single character
#include <vector>	
#include <string>
#include <iostream>

using  namespace std;

bool isPalindromic(const string&s, int l, int r) {
  while (l < r) {
    if (s[l++] != s[r--]) return false;
  }
  return true;
}

void palindromicDecomposition(const string& s, int prefix_idx, vector<vector<string>>* decompositions, vector<string>* decomposition) {
  if (prefix_idx >= s.size()) {
    decompositions->push_back(*decomposition);
    return;
  }

  for (int i = prefix_idx; i < s.size(); ++i) {
    if (isPalindromic(s, prefix_idx, i)) {
      decomposition->emplace_back(s, prefix_idx, i - prefix_idx+1);
      palindromicDecomposition(s, i + 1, decompositions, decomposition);
      decomposition->pop_back();
    }
  }

}

vector<vector<string>> palindromicDecomposition(const string& s) {
  vector<vector<string>> result;
  vector<string> current;
  palindromicDecomposition(s, 0, &result, &current);
  return result;
}

int main(void) {
  string s{ "0204451881" };
  auto d =  palindromicDecomposition(s);
}

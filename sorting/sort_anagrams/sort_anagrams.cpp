#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using std::cout;
using std::sort;
using std::string;
using std::unordered_map;
using std::vector;

void sortAnagrams(vector<string>& a) {
  unordered_map<string,vector<string>> hash;

  //array to hash table
  for (auto s : a) {
    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());
    hash[sorted_s].push_back(s);
  }

  //hash table to array
  int idx = 0;
  for (const auto hash_entry : hash) {
    for (const auto s : hash_entry.second) {
      a[idx++] = s;
    }
  }
}

int main(void) {
  vector<string> a = {"abc","mamma","bac","ammma","bca","pizza","aammm"};
  for (string& s : a) cout << s << "\n";
  sortAnagrams(a);
  for (string& s : a) cout << s << "\n";
}


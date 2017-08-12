//algorithm to find the distance between the nearest repeated entry
//of an array
//O(n) time; O(d) where d is the number of different entries

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits>

using std::string;
using std::unordered_map;
using std::vector;

template <typename T>
int nearestRepeatedEntry (const vector<T>& s) {
  unordered_map<string, int> entry_to_last_idx;
  int min_distance = std::numeric_limits<int>::max();
  for (int i = 0; i < s.size(); ++i) {
    auto got = entry_to_last_idx.find(s[i]);
    if (got != entry_to_last_idx.end()) {
      int distance = i - got->second;
      if (distance < min_distance) min_distance = distance;
      got->second = i;
    }
    else entry_to_last_idx.insert({s[i],i});  
  }
  return min_distance;
}

#if 0
//can be optimized: storing the min_distance for each string is not
//necessary; only the min distance considering all string is enough
struct EntryInfo {
  int last_position;
  int min_distance;
};

int nearestRepeatedEntry (const vector<string>& s) {
  unordered_map<string, EntryInfo> entry_to_info;
  for (int i = 0; i < s.size(); ++i) {
    auto got = entry_to_info.find(s[i]);
    if (got != entry_to_info.end()) {
      int distance = i - got->second.last_position;
      if (distance < got->second.min_distance) got->second.min_distance = distance;
      got->second.last_position = i;
    }
    else {
      entry_to_info.insert({s[i],{i,10000}});
    }
  }
  int min_distance = 10000;
  for (auto entry : entry_to_info) {
    if (entry.second.min_distance < min_distance) {
      min_distance = entry.second.min_distance;
    }
  }
  return min_distance;
}
#endif

int main (void) {
  vector<string> s{"All","work","and","no","play","makes","for",
      "no","work","no","fun","and","no","result"};

  std::cout << nearestRepeatedEntry(s);
}

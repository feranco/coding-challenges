//algorithm to find the size of the longest interval conteined into an array of integers
//O(n) time, O(n) space

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>


int longestConteinedInterval (const std::vector<int>& a) {
  std::unordered_set<int> not_in_interval(a.begin(),a.end());

  int max_interval_size = 0;

  for (int x:a) {
    //the following two checks are not necessary: cycling until the set is not empty
    // taking each time the first element is the same
    if (not_in_interval.empty() || not_in_interval.size() < max_interval_size) break;
    if (not_in_interval.find(x) == not_in_interval.end()) continue;
    int interval_size = 1, next = x+1, prev = x-1;
    while (not_in_interval.find(next) != not_in_interval.end()) {
      not_in_interval.erase(x);
      ++interval_size;
      ++next;
    }
    while (not_in_interval.find(prev) != not_in_interval.end()) {
      not_in_interval.erase(x);
      ++interval_size;
      ++prev;
    }
    max_interval_size = std::max(interval_size, max_interval_size);
  }
  return max_interval_size;
}

int main (void) {
  std::vector<int> a{3,-2,7,9,8,1,2,0,-1,5,8};
  std::cout << longestConteinedInterval(a);
}

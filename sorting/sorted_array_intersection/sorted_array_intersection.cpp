//algorithm to find the intersection of two sorted integer arrays
//first solution: binary search O(mlog(n)) where n is the size of the bigger array
//second solution: scan both arays from left to right O(m+n)

#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

vector<int> findIntersection(const vector<int>& a, const vector<int>& b) {
  vector<int> result;
  int idx_a = 0, idx_b = 0;

  while (idx_a < a.size() && idx_b < b.size()) {
    if (a[idx_a] == b[idx_b] && (idx_a == 0 || a[idx_a] != a[idx_a - 1])) {
      result.emplace_back(a[idx_a]);
      ++idx_a, ++idx_b;
    }
    else if (a[idx_a] < b[idx_b]) ++idx_a;
    else ++idx_b;
  }
  return result;
}

vector<int> findIntersectionBS(const vector<int>& a, const vector<int>& b) {
  vector<int> result;
  const vector<int>& outer = (a.size() < b.size() ? a : b);
  const vector<int>& inner = (a.size() < b.size() ? b : a);

  for (auto it = outer.cbegin(); it != outer.cend(); it++) {
    if (it != outer.cbegin() && *it == *(prev(it))) continue;
    bool got = binary_search(inner.begin(), inner.end(), *it);
    if (got) result.emplace_back(*it);
  }
  return result;
}

int main(void) {
  vector<int> a{ 2,3,3,5,5,6,7,7,8,12 };
  vector<int> b{ 5,5,6,8,8,9,10,10 };
  auto intersection = findIntersection(a, b);
  auto intersectionBS = findIntersectionBS(a, b);
  for_each(intersection.begin(), intersection.end(),
	   [](int x) {cout << x << " "; });
  for_each(intersectionBS.begin(), intersectionBS.end(),
	   [](int x) {cout << x << " "; });
}

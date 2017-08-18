//algorithm to find the intersection of two sorted integer arrays
//first solution: binary search O(mlog(n)) where n is the size of the bigger array
//second solution: scan both arays from left to right O(m+n)

#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

struct Interval {
private:
  struct Endpoint {
    int value;
    bool is_open;
  };
public:
  Endpoint start, end;
  void update(Endpoint e1, Endpoint e2) { start = e1; end = e2; }
  bool operator<(const Interval& rhs) const {
    return (start.value != rhs.start.value) ? (start.value < rhs.start.value) : !(start.is_open);
  }
};

vector<Interval> unionOfIntervals(vector<Interval> intervals) {
  vector<Interval> unions;
  sort(intervals.begin(), intervals.end());

  Interval current_union{ intervals.begin()->start,intervals.begin()->end };

  for (auto it = intervals.begin(); it != intervals.end(); ++it) {
    if (it->start.value <= current_union.end.value) {
      if (it->end.value > current_union.end.value) current_union.end = it->end;
      else if (it->end.value == current_union.end.value && !(it->end.is_open))
	current_union.end = it->end;

    }
    else {
      unions.emplace_back(current_union);
      current_union.update(it->start, it->end);
    }
  }
  unions.emplace_back(current_union);
  return unions;
}

int main(void) {
  vector<Interval> intervals{ {{ 0,true },{ 3,true }}, {{ 1,false },{ 1,false }}, {{ 5,false },{ 7,true }}, {{ 9,true },{11,false }}, 
			{{ 12,false },{14,false }}, {{ 3,false },{ 4,true }}, {{ 7,true },{ 8,true }}, {{ 12,true },{ 16,false }}, {{ 2,false },{ 4,false }},
			{{ 8,false },{ 11,true }}, { { 16,true },{ 17,true } } };
  auto unions = unionOfIntervals(intervals);
}

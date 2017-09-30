//algorithm to merge a set of disjoint closed intervals with a new interval
//O(n)
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Interval {
  int start, end;
};

Interval mergeIntersected (const Interval& a, const Interval& b) {
  return{min(a.start, b.start), max(a.end,b.end)}; //intersection
}

vector<Interval> merge (const vector<Interval>& disjoint_intervals, Interval added_interval) {
  vector<Interval> result;
  int it = 0;

  //add all intervals before added_interval
  while (it < disjoint_intervals.size() && added_interval.start > disjoint_intervals[it].end)
    result.emplace_back(disjoint_intervals[it++]);

  //merge all intervals intersecting with added_interval
  while (it < disjoint_intervals.size() && added_interval.end > disjoint_intervals[it].start)
    added_interval = mergeIntersected(added_interval, disjoint_intervals[it++]);
  //add merged intervals
  result.emplace_back(added_interval);
  //add all intervals after  added_interval
  while (it < disjoint_intervals.size())
    result.emplace_back(disjoint_intervals[it++]);

  return result;

}

int main (void) {
  vector<Interval> intervals{{-4,-1},{0,2},{3,6},{7,9},{12,13},{14,17}};
  Interval added{10,11};
  auto merged = merge(intervals, added);
  for (const auto& interval : merged)
    cout << "(" << interval.start << "," << interval.end << ")" << " ";   
}

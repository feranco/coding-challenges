#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#include <iterator>
using std::function;
using std::priority_queue;
using std::vector;


struct SequenceInfo {
  vector<int>::const_iterator current; //vector elements are not modified
  vector<int>::const_iterator end;
};

vector<int> mergeSortedSequences (const vector<vector<int>>& sequences) {

  auto cmp = [](SequenceInfo a, SequenceInfo b){return *(a.current) > *(b.current);};
  priority_queue<SequenceInfo, vector<SequenceInfo>, decltype(cmp)> min_heap(cmp);

  vector<int> result;
  
  for (const auto& seq : sequences) {
    if (!seq.empty()) min_heap.emplace(SequenceInfo{seq.begin(),seq.end()}); //important emplace
  }

  while (!min_heap.empty()) {
    auto min = min_heap.top();
    min_heap.pop();
    result.emplace_back(*min.current);
    if (++min.current != min.end) min_heap.emplace(SequenceInfo{min.current,min.end});
    
  }
  return result;
}

//without iterators
#if 0
struct SequenceInfo {
  int id;
  int idx;
  int data;
};

vector<int> mergeSortedSequences (const vector<vector<int>>& sequences) {

  auto cmp = [](SequenceInfo a, SequenceInfo b){return a.data > b.data;};
  priority_queue<SequenceInfo, vector<SequenceInfo>, decltype(cmp)> min_heap(cmp);

  vector<int> result;
  
  for (int i = 0; i != (int)sequences.size(); ++i) {
    if (!sequences[i].empty()) min_heap.push({i, 0, sequences[i][0]}); //empty vector
  }

  while (!min_heap.empty()) {
    auto min = min_heap.top();
    min_heap.pop();
    if (++min.idx < (int)sequences[min.id].size()) min_heap.push({min.id,min.idx,sequences[min.id][min.idx]});
    result.emplace_back(min.data);
  }
  return result;
}
#endif

int main (void) {
  vector<vector<int>> sequences{{3,5,7},{0,6},{0,6,28}};
  auto merged = mergeSortedSequences (sequences);
  for (auto m : merged) std::cout << m << " ";
}

//algorithm to find the index delimiting the smallest subarray
//covering a give set of element

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <list>
#include <iterator>
using std::string;
using std::vector;

struct SubarrayInfo {
  int start, end;
};

template <typename T>
SubarrayInfo smallestSubarrayCoveringSet (const vector<T>& a,
					  const vector<T>& set) {
  SubarrayInfo indices{0,0};
  std::unordered_map<T,std::list<int>::iterator> last_position;
  std::list<int> sorted_positions;

  for (auto x : set) last_position.insert({x, sorted_positions.end()});

  for (int i = 0; i < a.size() && sorted_positions.size() < set.size(); ++i) {
    auto got = last_position.find(a[i]);
    if (got != last_position.end()) {
      sorted_positions.push_back(i);
      got->second = std::prev(sorted_positions.end());
    }
  }

  indices.start = sorted_positions.front();
  indices.end = sorted_positions.back();

  for (int i = indices.end; i < a.size(); ++i) {
    auto got = last_position.find(a[i]);
    if (got != last_position.end()) {
      sorted_positions.erase(got->second);
      sorted_positions.push_back(i);
      got->second = std::prev(sorted_positions.end());
      if ((i - sorted_positions.front()) < (indices.end - indices.start)) {
	indices.end = i;
	indices.start = sorted_positions.front();
      }
    }
  }
  
  return indices;
}

/*
Base idea is good, but priority queue is not good because doesn't allow to replace the key associated 
to a specific value efficiently (stl doesn't implement erase); in the algorithm below there is a hash table
mapping element to index and a priority queue sorting the indices --> the right structure is the one that map directly
each element to its sorted position
template <typename T>
SubarrayInfo smallestSubarrayCoveringSet (const vector<T>& a,
					  const vector<T>& set) {
  SubarrayInfo indices{0,0};
  std::unordered_map<T,int> last_position;
  std::priority_queue<int> min_heap;

  for (auto x : set) last_position.insert({x,-1});

  for (int i = 0; i < a.size() || min_heap.size() < set.size(); ++i) {
    auto got = last_position.find(a[i]);
    if (got != last_position.end()) {
      if (min_heap.size() == 0) indices.start = i;
      if (min_heap.size() == set.size()) indices.end = i;
      min_heap.insert(i);
      got->second = i;
    }
  }

  for (int i = 0; i < a.size(); ++i) {
    auto got = last_position.find(a[i]);
    if (got != last_position.end()) {
      min_heap.erase(got->second);
      min_heap.insert(i);
      got->second = i;
      if ((i - min_heap.top()) < (indices.end - indices.start)) {
	indices.end = i;
	indices.start = min_heap.top();
      }
    }
  }
  
  return indices;
}
*/

int main (void) {
  vector<string> s{"My","paramount","object","in","this","struggle",
      "is","to","save","the","Union","and","not",
      "to","destroy","slavery","If","I","could","save",
      "life","but","not","Union","who","cares","about"};
  vector<string> set{"save","Union"};
  auto min_subarray =  smallestSubarrayCoveringSet(s,set);
  std::cout <<  min_subarray.start << " " <<  min_subarray.end ;

  vector<int> a{1,2,1,1,3,4,1,3,2,1,4,3};
  vector<int> a_set{2,4};
   auto min_a_subarray =  smallestSubarrayCoveringSet(a,a_set);
  std::cout <<  min_a_subarray.start << " " <<  min_a_subarray.end ;
}

//algorithm to find the longest distinct subarray 
//O(n)
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

template <typename T>
int longestDistinctSubarray (const vector<T>& array) {
  //map each distinct element in the current subarray 
  //to the lenght of the subarray
  unordered_map<T,int> last_occurrence;
  int longest = 0, length = 0, start = 0;
  for (int i = 0; i < array.size(); ++i) {
    if (last_occurrence.find(array[i]) ==  last_occurrence.end()) {
      last_occurrence[array[i]] = i;
      ++length;
    }
    else {
      if (last_occurrence.at(array[i]) > start) {
	length = i - last_occurrence.at(array[i]) ;
	start = last_occurrence.at(array[i])+1;
	last_occurrence[array[i]] = i;
      }
      else {last_occurrence[array[i]] = i; ++length;}
    }
    longest = max(longest,length);
  }
  return longest;
}

int main(void) {
  vector<string> characters{"f","s","f","e","t","w","e","n","w","f","t","e",};
  cout << longestDistinctSubarray(characters) << endl;
	
}

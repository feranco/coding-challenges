//algorithm to find the index delimiting the smallest subarray
//covering a give set of element

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

struct SubarrayInfo {
  int start, end;
};

struct SubarrayKeyInfo {
  int last_position;
  int subarray
};

//cycle over array;
//for each element that is also in the set, check the size of the
//subarray that end in that element (index of the current element -
//min(other element last position)); if the subarray size in less than the
//old min, overwrite indices

SubarrayInfo smallestSubarrayCoveringSet (const vector<string>& s,
					  const vector<string>& set) {
  uno
}

int main (void) {
  vector<string> s{"My","paramount","object","in","this","struggle",
      "is","to","save","the","Union","and","not",
      "to","destroy","slavery","If","I","could","save",
      "life","but","not","Union","who","cares","about"};
  vector<string> set{"save","Union"};
  std::cout << isPalindromicPermutable(s);
}

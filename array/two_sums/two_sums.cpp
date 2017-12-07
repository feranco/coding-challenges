#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>

using namespace std;

//O(n^2) time O(1) space 
/*
vector<int> twoSum(vector<int>& nums, int target) {
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i+1; j < nums.size(); ++j) {
      if (nums[i] + nums[j] == target) {
	return {i,j};
      }
                    
    }
  }
  return {};
}
*/

//O(n) time O(n) space
vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int,int> numToIndex({{nums[0],0}});
  for (int i = 1; i < nums.size(); ++i) {
    if (numToIndex.find(target - nums[i]) != numToIndex.end()) {
      return {numToIndex.find(target - nums[i])->second, i};
    }
    //numToIndex.insert(std::make_pair(nums[i],i));
    numToIndex.emplace(nums[i],i);
  }
  return {};
}

int main(void) {
  vector<int> nums{3,2,4};
  auto indices = twoSum(nums,6);
  if (indices[0] == 1 && indices[1] == 2)
    cout << "Correct!";
  else
    cout << "Wrong!";
}
        

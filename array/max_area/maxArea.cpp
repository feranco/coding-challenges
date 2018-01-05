/*****************************************************************************************************************/
 /* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container and n is at least 2.
 * https://leetcode.com/problems/container-with-most-water/description/
/***************************************************************************************************************/

#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// Brute force solution using two pointers: O(n^2)
// For each line l iterate through all the previous lines
// computing the area between l and the previous one and
// updating the max area when required
int maxArea(vector<int>& height) {

  int maxArea = 0;
  
  for (int i = 1; i < height.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      int area = min(height[i],height[j]) * (i-j); //max area ending at line i
      maxArea = max(area,maxArea);
    }
  }

  return maxArea;
}


// Observation: the area with max width is the one bounded by
// the first and the last line; reducing the width the area can increase
// only if the height of the lines increases. So in each step it's possible to discard
// the shorter line.
// O(n)

int maxArea(vector<int>& height) {
  int l = 0, r = height.size()-1;
  int maxArea = min(height[l],height[r]) * (r-l);
        
  while (l < r) {
    (height[l] < height[r]) ? l++ : r--;
    int area = min(height[l],height[r]) * (r-l);
    maxArea = max(maxArea,area);
  }
  return maxArea;
}



//algorithm to find the range of a value in a sorted array
//O(logn)
#include <vector>	
#include <iostream>

using  namespace std;

vector<int> searchRange(const vector<int> &a, int target) {
  int l = 0, r = a.size() - 1;
  vector<int> range{ -1,-1 };

  while (l <= r) {
    int m = l + (r - l) / 2;
    if (target < a[m]) r = m - 1;
    else if (target > a[m]) l = m + 1;
    else {
      range[0] = m, range[1] = m;
      //look for left limit
      int r_left = m;
      while (l < r_left) {
	int m_left = l + (r_left - l) / 2;
	if (a[m_left] < a[m]) l = m_left + 1;
	else r_left = m_left;
      }
      range[0] = r_left;
      //look for right limit
      int l_right = m;
      while (l_right < r) {
	int m_right = l_right + (r - l_right+1) / 2;
	if (a[m_right] > a[m]) r = m_right - 1;
	else l_right = m_right;
				
      }
      range[1] = l_right;
      break;
    }
  }
  return range;
}


int main(void) {
  vector<int> input{8,9,9,9,9,9,10 };
  auto r = searchRange(input,9);
  cout << "(" << r[0] << "," << r[1] << ")";
}

//algorithm to detect if an element is contained in a sorted matrix
//Two implementations:
//1) the up right corner is iteratively compared with the targed, removing
// a row or a column according to the outcome 
//O(m+n) time (worst case a row removal is alternated to a column removal) O(1) space
//2) binary search is applied to the diagonal partitioning the matrix in four quadrants;
// the method is recursively applied to the two quadrants where it is still possible find the target
// O(log(min(m,n)) time

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

template <typename T>
bool searchSortedMatrix (const vector<vector<T>>& matrix, T target) {
  size_t rows = matrix.size(), cols = matrix[0].size();
  if (target < matrix[0][0] || target > matrix[rows-1][cols-1]) return false;
  size_t r = 0, c = cols-1;
  while (r < rows && c < cols) {
    if (target == matrix[r][c]) return true;
    if (target < matrix[r][c]) c--;
    else r++;
  }
  return false;
}

struct Point {
  int x;
  int y;
  template <typename T>
  bool isValid(const vector<vector<T>>& matrix) {
    if (x < 0 || x > matrix.size() ||
	y < 0 || y > matrix[0].size()) return false;
    return true;
  }
  bool operator<=(const Point& rhs) {
    if (x > rhs.x || y > rhs.y) return false;
    return true;
  }
};

/* Set the end of the diagonal of the matrix, considering that it may not be square*/
Point setDownRight(const Point& up_left, const Point& down_right) {
  int diff_x = down_right.x - up_left.x;
  int diff_y = down_right.y - up_left.y;
  return{ std::min(down_right.x,up_left.x + diff_y), std::min(up_left.y + diff_x,down_right.y) };
  /*
  if (diff_x == diff_y) return{ down_right.x, down_right.y };
  if (diff_x < diff_y) return{ down_right.x, up_left.y + diff_x };
  else  return{ up_left.x + diff_y, down_right.y };
  */
}

template <typename T>
bool searchSortedMatrix(const vector<vector<T>>& matrix, Point up_left, Point down_right, T target) {
	
  //check corner validity
  if (!up_left.isValid(matrix) || !down_right.isValid(matrix)) return false;
  //check diagonal validity
  if (!(up_left <= down_right)) return false;

  Point l = up_left, r = setDownRight(up_left, down_right);

  while (l <= r) {
    Point m{ (r.x + l.x) / 2, (r.y + l.y) / 2 };
    if (matrix[m.x][m.y] == target) return true;
    if (matrix[m.x][m.y] < target) l = { m.x + 1,m.y + 1 };
    else r = { m.x - 1,m.y - 1 };
  }
  //continue search in the two possible quadrants
  return searchSortedMatrix(matrix, { r.x + 1,up_left.y }, { down_right.x, r.y }, target) ||
    searchSortedMatrix(matrix, { up_left.x,l.y }, { l.x - 1, down_right.y }, target);
		
}

int main (void) {
  vector<vector<int>> matrix{{-1,2,4,4,6},{1,5,5,9,21},{3,6,6,9,22},{3,6,8,10,24},
			     {6,8,9,12,25},{11,13,14,16,40}};

  cout << searchSortedMatrix(matrix, 15);
  cout << searchSortedMatrix(matrix, { 0,0 }, { (int)matrix.size()-1, (int)matrix[0].size()-1 }, 7);
}

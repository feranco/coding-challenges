#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
/*
const int size_x = 4;
const int size_y = 4;

static int paths = 0;


void findPaths(int curr_x, int curr_y) {
	if (curr_x >= size_x || curr_y >= size_y) return;
	if ((curr_x == (size_x - 1)) && (curr_y == (size_y - 1))) paths++;
	findPaths(curr_x, curr_y + 1);
	findPaths(curr_x+1, curr_y);
}
*/

struct Coordinate {
  int x;
  int y;
  Coordinate(int x, int y) : x(x), y(y) {}
  bool operator==(const Coordinate& rhs) const {return (x == rhs.x && y == rhs.y);}
};

namespace std
{
  template <>
  struct hash<Coordinate>
  {
    size_t operator()(Coordinate const & x) const noexcept
    {
      return (
	      (51 + std::hash<int>()(x.x)) * 51
	      + std::hash<int>()(x.y));
    }
  };
}

class Grid {
  int** grid;
  int size_x, size_y;
  int findPath (Coordinate curr, vector<Coordinate>& path, unordered_set<Coordinate>& visited);
  bool isFree (Coordinate cell);
public:
  Grid (int sz_x, int sz_y);
  bool findPath (vector<Coordinate>& path);
};

Grid::Grid (int sz_x, int sz_y): size_x(sz_x), size_y(sz_y) {
  grid = new int*[size_x];
  for (int i = 0; i < size_x; ++i) {
    grid[i] = new int[size_y];
    for (int j = 0; j < size_y; ++j) {
      grid[i][j] = 1;
    }
  }
}

bool Grid::isFree (Coordinate cell) {
  if (cell.x >= 0 && cell.x < size_x && cell.y >= 0 && cell.y < size_y) return grid[cell.x][cell.y];
  return false;
}

bool Grid::findPath (vector<Coordinate>& path) {
  Coordinate start(0,0);
  unordered_set<Coordinate> visited;
  return findPath(start, path, visited);
}

int Grid::findPath(Coordinate curr, vector<Coordinate>& path, unordered_set<Coordinate>& visited) {
  if (curr.x >= size_x || curr.y >= size_y || !isFree(curr) || !(visited.find(curr) == visited.end())) return false;

  
  Coordinate moveRight(curr.x+1, curr.y);
  Coordinate moveDown(curr.x, curr.y+1);
  if (curr.x == (size_x - 1) && curr.y == (size_y - 1) && !findPath(moveRight, path, visited) && !findPath(moveDown, path, visited)) {
    path.push_back(curr);
    return true;
  }
  visited.insert(curr);
  return false;
}

int main(void) {
  vector<Coordinate> path;
  Grid grid(3,3);
  if (grid.findPath(path)) {
    for (auto p : path) {
      cout << "(" << p.x << " " << p.y <<") ";
    }
  }
  //cout << paths;
}

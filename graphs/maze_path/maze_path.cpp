//algorithm to find a path in a maze
//Assumption:
//1) maze is modelled by a graph: vertex are white cells and edges connections between white cells
//2)

enum class Color {BLACK, WHITE};

struct Coordinate {
  int x, y;
  bool isValid (const vector<vector<bool>>& maze) {
    return (x >= 0 && x < maze.size() &&
	    y >= 0 && y < maze[0].size());
  }
  bool operator== (const Coordinate& rhs) const {
    return (x == rhs.x && y == rhs.y);
  }
};

vector<Coordinate> findPathHelper (const vector<vector<bool>>& maze,
			     const Coordinate& start, const Coordinate& end) {

vector<Coordinate> findPath (const vector<vector<bool>>& maze,
			     const Coordinate& start, const Coordinate& end) {
  vector<vector<bool>> visited((vector<bool>, maze.size()), maze[0].size());
}

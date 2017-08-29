//algorithm to find a path in a maze
//Assumption:
//1) maze is modelled by a graph: vertex are white cells and edges connections between white cells
//2) implementation with dfs find a path in O(V + E)
//2) implementation with bfs find the shortest path in O(V + E)
#include <array>
#include <queue>
#include <random>
#include <vector>

using namespace std;

enum class Color { BLACK, WHITE };

struct Coordinate {
  int x, y;
  bool isValid(const vector<vector<Color>>& maze) {
    return (x >= 0 && x < maze.size() &&
	    y >= 0 && y < maze[0].size() && 
	    maze[x][y] == Color::WHITE);
  }
  bool operator== (const Coordinate& rhs) const {
    return (x == rhs.x && y == rhs.y);
  }
};

//return true if end has been found, false otherwise
bool findPathHelper(const vector<vector<Color>>& maze,
		    Coordinate current, const Coordinate& end,
		    vector<vector<bool>>* visited, vector<Coordinate>* path) {

  //check if current coordinate is valid or already visited				 
  if (!current.isValid(maze) || (*visited)[current.x][current.y]) return false;

  //mark the current coordinate as visited and add to the path
  (*visited)[current.x][current.y] = true;
  path->emplace_back(current);

  //check if the end of the path has been found
  if (current == end) return true;

  bool found = findPathHelper(maze, { current.x - 1, current.y }, end, visited, path) ||
    findPathHelper(maze, { current.x, current.y - 1 }, end, visited, path) ||
    findPathHelper(maze, { current.x + 1, current.y }, end, visited, path) ||
    findPathHelper(maze, { current.x, current.y + 1 }, end, visited, path);

  if (!found) path->pop_back();
  return found;
}

vector<Coordinate> findPath(const vector<vector<Color>>& maze,
			    const Coordinate& start, const Coordinate& end) {

  vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(),false));
  vector<Coordinate> path;
  findPathHelper(maze, { start.x, start.y }, end, &visited, &path);
  return path;
}

vector<Coordinate> getPath(const Coordinate& start, const Coordinate& end, const vector<vector<Coordinate>>& parent, vector<Coordinate>& path) {
	
  if (start == end)  path.emplace_back(start);
  else{
    getPath(start, parent[end.x][end.y], parent,path);
    path.emplace_back(end);
  }
	
  return path;
}

vector<Coordinate> findShortestPath(const vector<vector<Color>>& maze,
				    const Coordinate& start, const Coordinate& end) {

  queue<Coordinate> bfs_queue;
  vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
  vector<vector<Coordinate>> parent(maze.size(), vector<Coordinate>(maze[0].size(), {-1,-1}));

  //enqueue the starting node and mark it as visited
  bfs_queue.emplace(start);
  visited[start.x][start.y] = true;

  while (!bfs_queue.empty()) {
    auto current = bfs_queue.front();
    bfs_queue.pop();

    if (current == end) break;
    const vector<Coordinate> movements{ { -1,0 },{ 0,-1 },{ 1,0 },{ 0,1 } };

    for (const auto& movement : movements) {
      Coordinate next{ current.x + movement.x, current.y + movement.y };
      //if the next vertex is valid 
      if (next.isValid(maze) && !visited[next.x][next.y]) {
	bfs_queue.emplace(next);
	visited[next.x][next.y] = true;
	parent[next.x][next.y] = current;
      }
    }
  }

  if (parent[end.x][end.y] == Coordinate{-1, -1}) return{};
  vector<Coordinate> path;
  return getPath(start, end, parent,path);
}

int main(void) {
  vector<vector<Color>> maze(4, vector<Color>(4, Color::WHITE));
  random_device rdev{};
  default_random_engine e{ rdev() };
  uniform_int_distribution<> d{ 0, 3 };
  for (int i = 0; i < 4; ++i) maze[d(e)][d(e)] = Color::BLACK;
  Coordinate start{ 0,0 }, end{ 3,3 };
  auto path = findShortestPath(maze, start, end);
}

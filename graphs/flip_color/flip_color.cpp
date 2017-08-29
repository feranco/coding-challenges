//algorithm to find a path in a maze
//Assumption:
//1) maze is modelled by a graph: vertex are white cells and edges connections between white cells
//2) implementation with dfs find a path in O(V + E)
//2) implementation with bfs find the shortest path in O(V + E)

#include <iostream>
#include <random>
#include <vector>

using namespace std;

enum class Color { BLACK, WHITE };

struct Coordinate {
  int x, y;
  bool isValid(const vector<vector<Color>>& image) const{
    return (x >= 0 && x < image.size() &&
	    y >= 0 && y < image[0].size());
  }
  bool operator== (const Coordinate& rhs) const {
    return (x == rhs.x && y == rhs.y);
  }
};

//visited is not necessary because to flipped color can be considered a marker
void flipColor (vector<vector<Color>>* image_ptr, const Coordinate& px_to_flip, Color target) {

  vector<vector<Color>>& image = *image_ptr;
  //check if the current pixel is valid and has not been already flipped 
  if (!px_to_flip.isValid(image) || image[px_to_flip.x][px_to_flip.y] == target) return;

  //flip the current pixel
  image[px_to_flip.x][px_to_flip.y] = target;

  const vector<Coordinate> movements{{-1,0},{0,-1},{1,0},{0,1}};

  for (auto movement : movements) {
    Coordinate next{px_to_flip.x + movement.x, px_to_flip.y + movement.y};
    flipColor(image_ptr, next, target);
  }
  
}

const int n = 10;
const int m = 15;

void printImg (const vector<vector<Color>>& image) {
  for (auto row : image) {
    for (auto col : row) {
      if (col ==  Color::WHITE) cout << "1";
      else cout << "0";
    }
    cout << "\n";
  }
}

int main (void) {
  vector<vector<Color>> image(n, vector<Color>(m, Color::WHITE));
  random_device rdev{};
  default_random_engine e{ rdev() };
  uniform_int_distribution<> d_row{ 0, n-1 };
  uniform_int_distribution<> d_col{ 0, m-1 };
  for (int i = 0; i < ((n*m)/4); ++i) image[d_row(e)][d_col(e)] = Color::BLACK;
  printImg(image);
  Coordinate start{ d_row(e), d_col(e)};
  cout << "Start: " << start.x << " " << start.y << "\n";
  flipColor(&image, start, (image[start.x][start.y] == Color::WHITE) ? Color::BLACK : Color::WHITE);
  printImg(image);
}

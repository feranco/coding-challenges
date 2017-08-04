#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using std::pow;
using std::ifstream;
using std::priority_queue;
using std::vector;

struct Star {
  double x, y, z;
  bool operator< (const Star& rhs)  const{
    return sqrt(pow(x,2)+pow(y,2)+pow(z,2)) < sqrt(pow(rhs.x,2)+pow(rhs.y,2)+pow(rhs.z,2));
  }
};

vector<Star> findClosestStars (int k, ifstream& is) {
  
  vector<Star> result;
  priority_queue<Star> max_heap; 
  double x, y, z;
  while (is >> x >> y >> z) {
    max_heap.emplace(Star{x, y, z});
    if (max_heap.size() > k) {
      max_heap.pop();
    }
  }

  while (!max_heap.empty()) {
    result.emplace_back(max_heap.top());
    max_heap.pop();
  }
  return result;
}

int main (void) {
  ifstream ifs("stars.txt");
  if (ifs) {
    auto closest_stars = findClosestStars(3, ifs);
  for (auto star : closest_stars) std::cout << star.x << star.y << star.z << "\n";
  }
}



#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;

struct Box {
  int w, h, d;
  Box (): w(-1), h(-1), d(-1){}
  Box (int width, int height, int depth): w(width), h(height), d(depth){}
  bool operator<(const Box& rhs);
  bool operator==(const Box& rhs) const;
  bool isNull (void) const;
};

bool Box::operator<(const Box& rhs) {
  return (w < rhs.w && h < rhs.h && d < rhs.d);
}

bool Box::operator==(const Box& rhs) const{
  return (w == rhs.w && h == rhs.h && d == rhs.d);
}

bool Box::isNull (void) const{
  return (w < 0 || h < 0 || d < 0);
}

namespace std
{
  template <>
  struct hash<Box>
  {
    size_t operator()(Box const & x) const noexcept
    {
      return (
	      (51 + std::hash<int>()(x.w)) * 51
	      + std::hash<int>()(x.h) * 51
	      + std::hash<int>()(x.d));
    }
  };
}

#if 0
/*
struct StackOfBox {
  int height;
  vector<Box> stack;
};
*/
void findMaxStack(const vector<Box>& box, Box bottom, unordered_map<Box, vector<Box>>& maxStack) {
  for (auto current : box) {
    if (current < bottom) {
      auto current_box = maxStack.find(current);
      auto bottom_box = maxStack.find(bottom);
      if (current_box != maxStack.end()) box.insert(bottom_box->second.end(),current_box->second.begin(),current_box->second.end());
      else bottom_box->second.push_back(current);
    findMaxStack(box, bottom, maxStack);
    }
  }
}

vector<Box> findMaxStack (const vector<Box>& boxes) {
  unordered_map<Box, vector<Box>> maxHeightStacks;
  for (auto box : boxes) {
    vector<Box> maxHeightStack = findMaxStack(boxes, box, maxHeightStacks);
  }
  return maxHeightStack;
}
#endif

int getHeight (const vector<Box>& stack) {
  int height = 0;
  for (auto box : stack) height += box.h;
  return height;
}

vector<Box> findMaxStack(const vector<Box>& boxes, const Box& bottom, unordered_map<Box, vector<Box>>& cache) {
  
  int max_height = 0;  //max height with build over bottom 
  vector<Box> max_height_stack; //stack with max height with build over bottom

  auto cached_box = cache.find(bottom);
  if (cached_box != cache.end()) return cached_box->second;
  
  for (auto box : boxes) {
    //try to build a stack with all other boxes
    //that can be put over bottom
    if (bottom.isNull() || box < bottom) {
      auto stack = findMaxStack(boxes, box, cache);
      int height = getHeight(stack);
      if (height > max_height) {
	max_height = height;
	max_height_stack = stack;
      }
      //add bottom to that stack
      if(!bottom.isNull()) {
	max_height_stack.push_back(bottom);
	cache.insert({bottom, max_height_stack});
      }
    }
  }
  return  max_height_stack;
}

vector<Box> findMaxStack (const vector<Box>& boxes) {
  unordered_map<Box, vector<Box>> maxHeightStacks;
  Box empty;
  vector<Box> maxHeightStack = findMaxStack(boxes, empty, maxHeightStacks);
  for (auto box : maxHeightStack) std::cout << box.w << " " << box.h << " " << box.d << std::endl;
  return maxHeightStack;
}

int main (void) {
  vector<Box> boxes;
  boxes.emplace_back(Box(5,5,5));
  boxes.emplace_back(Box(4,4,4));
  boxes.emplace_back(Box(2,1,2));
  boxes.emplace_back(Box(3,2,3));
  boxes.emplace_back(Box(2,2,2));
  boxes.emplace_back(Box(1,1,1));
  findMaxStack(boxes);
}

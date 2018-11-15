#include <iostream>
#include <vector>

void oddIndices (const std::vector<int>& numbers, size_t idx) {
  if (idx >= numbers.size()) {
    std::cout << std::endl;
    return;
  }
  
  if (idx & 1) {
    std::cout << numbers[idx] << " ";
  }

  oddIndices(numbers, idx+1);
    
};

void oddIndices (const std::vector<int>& numbers) {
  oddIndices(numbers, 0);
}

int main (void) {
  std::vector<int> numbers{0,1,2,3,4,5,6,7,8};
  oddIndices(numbers);
}

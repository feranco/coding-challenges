#include "powerSetParams.h"
#include "powerSetReturn.h"
#include <iostream>
#include <vector>
#include <stdexcept>

int main(int argc, char**argv) {
  std::vector<char> items{ 'a','b','c','d' };
  
  auto powerSet = powerSetParams(items);
  auto samePowerSet = powerSetReturn(items);

  //not working because powerSetReturn build sets appending elements at the end of the vector
  //if (!std::equal(powerSet.begin(), powerSet.end(), samePowerSet.begin())) throw std::runtime_error("powerSetParams different from powerSetReturn"); 
  
  for (auto set : samePowerSet) {    
    for (auto item : set) {
      std::cout << item << " ";
    }
    std::cout << "\n";
  }
}

#include "powerSetParams.h"
#include "powerSetReturn.h"
#include <iostream>
#include <vector>
#include <stdexcept>

int main(int argc, char**argv) {
  std::vector<char> items{ 'a','b','c','d' };
  
  auto powerSet = powerSetParams(items);
  auto samePowerSet = powerSetReturn(items);
  
  for (auto set : powerSet) {
    if (!std::equal(set.begin(), set.end())) throw std::runtime_error("powerSetParams different from powerSetReturn");     
    for (auto item : set) std::cout << item << " ";
    std::cout << "\n";
    }
}

#include "staircaseStepsParams.h"
//#include "powerSetReturn.h"
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

int main(int argc, char**argv) {
  
  auto paths = staircaseStepsParams(atoi(argv[1]));
  //auto samePowerSet = powerSetReturn(items);

  //not working because powerSetReturn build sets appending elements at the end of the vector
  //if (!std::equal(powerSet.begin(), powerSet.end(), samePowerSet.begin())) throw std::runtime_error("powerSetParams different from powerSetReturn"); 
  
  for (auto path : paths) {    
    for (auto item : path) {
      std::cout << item << " ";
    }
    std::cout << "\n";
    }
}

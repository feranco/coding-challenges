#include "staircaseStepsParams.h"
#include "staircaseStepsReturn.h"
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

int main(int argc, char**argv) {
  
  auto paths = staircaseStepsParams(atoi(argv[1]));
  auto samePaths = staircaseStepsReturn(atoi(argv[1]));

  if (!std::equal(paths.begin(), paths.end(), samePaths.begin())) {
    throw std::runtime_error("staircaseStepsParams different from staircaseStepsReturn");
  }
  
  for (auto path : paths) {    
    for (auto item : path) {
      std::cout << item << " ";
    }
    std::cout << "\n";
  }
}

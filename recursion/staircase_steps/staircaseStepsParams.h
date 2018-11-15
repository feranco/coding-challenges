#include <list>
#include <vector>

using Path  = std::list<int>;
using Paths = std::vector<Path>;

void staircaseSteps (int n, int currentStep, Path currentPath, Paths& result) {
  
  if (currentStep == n) {
    currentPath.push_back(currentStep);
    result.push_back(currentPath);
    return;
  }

  if (currentStep > n) return;
  
  currentPath.push_back(currentStep);
  staircaseSteps(n, currentStep+1, currentPath, result);
  staircaseSteps(n, currentStep+2, currentPath, result);
  staircaseSteps(n, currentStep+3, currentPath, result);
}

std::vector<std::list<int>> staircaseStepsParams (int n) {
  Paths result;
  Path currentPath;
  staircaseSteps(n, 0, currentPath, result);
  return result;
}



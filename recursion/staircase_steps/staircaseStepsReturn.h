#include <list>
#include <vector>

using Path  = std::list<int>;
using Paths = std::vector<Path>;

Paths staircaseSteps (int n, int currentStep) {

  Paths result;
  
  if (currentStep == n) {
    Path lastStep{n};
    result.push_back(lastStep);
    return result;
  }

  if (currentStep > n) return result;

  auto oneStep =  staircaseSteps(n, currentStep+1);
  auto twoStep =  staircaseSteps(n, currentStep+2);
  auto thrStep =  staircaseSteps(n, currentStep+3);
  
  result.reserve(oneStep.size() + twoStep.size() + thrStep.size());
  result.insert(result.end(), oneStep.begin(), oneStep.end());
  result.insert(result.end(), twoStep.begin(), twoStep.end());
  result.insert(result.end(), thrStep.begin(), thrStep.end());

  for (auto& path : result) {
    path.push_front(currentStep);
  }

  return result;
}

Paths staircaseStepsReturn (int n) {
  return staircaseSteps(n, 0);
}

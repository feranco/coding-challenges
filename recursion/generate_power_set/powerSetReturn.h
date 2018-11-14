#include <vector>
#include <iostream>
template <typename T>
std::vector<std::vector<T>> powerSet (const std::vector<T>& set, unsigned int i) {
  
  if (i == set.size()) {
    std::vector<std::vector<T>> result;
    result.emplace_back(std::vector<T>());
    return result;
  }

  auto withoutCurrent = powerSet(set, i+1);
  auto withCurrent = result;

  for (std::vector<T> subset : withoutCurrent) {
    subset.push_back(set[i]);
    withCurrent.push_back(subset);
  }
  
  return withCurrent;
}

template <typename T>
std::vector<std::vector<T>> powerSetReturn (const std::vector<T>& set) {
  return powerSet(set, 0);
}





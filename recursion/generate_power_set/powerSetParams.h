#include <vector>

template <typename T>
void powerSet (const std::vector<T>& set, unsigned int i, std::vector<std::vector<T>>& result, std::vector<T> currentSet) {
  
  if (i == set.size()) {
    result.emplace_back(currentSet);
    return;
  }

  powerSet(set, i+1, result, currentSet);
  std::vector<T> currentSetWith = currentSet;
  currentSetWith.emplace_back(set[i]);
  powerSet(set, i+1, result, currentSetWith);
}

template <typename T>
std::vector<std::vector<T>> powerSetParams (const std::vector<T>& set) {
  std::vector<std::vector<T>> result;
  powerSet(set, 0, result, std::vector<T>());
  return result;
}





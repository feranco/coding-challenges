//algorithm generating all the possible placements of n queens in a nxn chessboard
//1) since two or more queens must be in different rows, a placement is coded
//with a vector of size n: each element represent the position of the queen in the corresponding row

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
bool isValidPermutation (const vector<T>& permutation) {
  const T& last = permutation.back();
  for (int i = 0; i < (permutation.size()-1); ++i) {
    if (last == permutation[i]) return false;
  }
  return true;
}

template <typename T>
void generatePermutations (const vector<T>& items, vector<vector<T>>* permutations,
			   vector<T>* curr_permutation) {
  //if is a solution, process solution
  if (curr_permutation->size() == items.size()) permutations->emplace_back(*curr_permutation);

  for (int i = 0; i < items.size(); ++i) {
    curr_permutation->emplace_back(items[i]);
    if (isValidPermutation(*curr_permutation)) {
      generatePermutations(items, permutations, curr_permutation);
    }
    curr_permutation->pop_back();
  }
}

template <typename T>
vector<vector<T>> generatePermutations (const vector<T>& items) {
  vector<vector<T>> permutations;
  vector<T> curr_permutation;
  generatePermutations(items, &permutations, &curr_permutation);
  return permutations;
}

int main(void) {
  vector<char> items{'a','b','c','d'};
  auto permutations = generatePermutations (items);
  for (auto permutation : permutations) {
    for (auto item : permutation) cout << item << " ";
    cout << "\n";
  }
}


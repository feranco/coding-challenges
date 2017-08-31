//algorithm generating all the possible permutations of a set of items
//The first approach uses backtracking, the second improves the first one introducing a vector of boolean keeping 
//track of which elements of the set are in the current permutation; this avoid to check all previous elements each 
//time a new one is inserted 

#include <iostream>
#include <vector>

using namespace std;

#if 0
//first approach
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
  //construct candidates and cycle over them
  for (int i = 0; i < items.size(); ++i) {
    curr_permutation->emplace_back(items[i]);//make move
    if (isValidPermutation(*curr_permutation)) {//prune not valid candidates
      generatePermutations(items, permutations, curr_permutation);
    }
    curr_permutation->pop_back();//unmake move
  }
}

template <typename T>
vector<vector<T>> generatePermutations (const vector<T>& items) {
  vector<vector<T>> permutations;
  vector<T> curr_permutation;
  generatePermutations(items, &permutations, &curr_permutation);
  return permutations;
}
#endif

template <typename T>
void generatePermutations(const vector<T>& items, vector<bool>* items_in_curr_permutation_ptr,
	vector<vector<T>>* permutations, vector<T>* curr_permutation) {
	
	vector<bool>& items_in_curr_permutation = *items_in_curr_permutation_ptr;
	
	//if is a solution, process solution
	if (curr_permutation->size() == items.size()) permutations->emplace_back(*curr_permutation);

	//construct candidates and cycle over them
	for (int i = 0; i < items.size(); ++i) {
		if (!items_in_curr_permutation[i]) {
			curr_permutation->emplace_back(items[i]);//make move
			items_in_curr_permutation[i] = true;
		  generatePermutations(items, items_in_curr_permutation_ptr, permutations, curr_permutation);
			curr_permutation->pop_back();//unmake move
			items_in_curr_permutation[i] = false;
		}
	}
}

template <typename T>
vector<vector<T>> generatePermutations(const vector<T>& items) {
	vector<vector<T>> permutations;
	vector<T> curr_permutation;
	vector<bool> items_in_curr_permutation(items.size(), false);
	generatePermutations(items, &items_in_curr_permutation, &permutations, &curr_permutation);
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


//algorithm generating all the possible permutations of a set of items
//The solution is similar to the one in generate_permutations.cpp
//This solution introduces the use of an hash set that keep track of
//the elements of the input a already used for the current element of the permutation
//O(n*n!): n! possible permutations, each permutation ha length n

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void generatePermutations (vector<int> &a, vector<int>* permutation, vector<bool>* in_permutation, vector<vector<int>>* result) {
    
    if (permutation->size() == a.size()) result->emplace_back(*permutation);
    
    unordered_set<int> used;
    for (int i = 0; i < a.size(); ++i) {
        if (!(*in_permutation)[i] && used.find(a[i]) == used.end()) {
            (*in_permutation)[i] = true;
            used.emplace(a[i]);
            permutation->emplace_back(a[i]);
            generatePermutations(a, permutation, in_permutation, result);
            (*in_permutation)[i] = false;
            permutation->pop_back();
        }
    }

}

vector<vector<int>> generatePermutations(vector<int> &a) {
    vector<vector<int>> result;
    vector<int> permutation;
    vector<bool> in_permutation(a.size(),false);
    generatePermutations(a, &permutation, &in_permutation, &result);
    return result;
}

int main(void) {
  vector<int> items{1,1,2};
  auto permutations = generatePermutations (items);
  for (auto permutation : permutations) {
    for (auto item : permutation) cout << item << " ";
    cout << "\n";
  }
}

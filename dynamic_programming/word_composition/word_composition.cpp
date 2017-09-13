//algorithm to check if a target word can be composed by
//other dictionary's words and find these words

#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// Solution 1: 
// Backtrack: find (recursively) a dictionary word matching
// the current target prefix until the target is 
// O(2^n)
// To get all possible decompositions:
// a)  pass a vector<vector<string>> to decomposeWordInDictionaryCache
// b)  in addition to return true emplace result to the vector<vector<string>>

bool decomposeWordInDictionary(const vector<string>& dictionary, const string& target, int prefix_idx, vector<string>* result) {
  if (prefix_idx >= target.size()) return true;

  for (const string& word : dictionary) {
    cout << word << " " << target.substr(prefix_idx, target.size()-prefix_idx) << endl;
    if (word.size() <= (target.size() - prefix_idx) &&
	word == target.substr(prefix_idx, word.size())) {
      result->emplace_back(word);
      if (decomposeWordInDictionary(dictionary, target, prefix_idx + word.size(), result)) {
	return true;
      }
      else {
	result->pop_back();
      }
    }
  }
  return false;
}

vector<string> decomposeWordInDictionary(const vector<string>& dictionary, const string& target) {
  vector<string> result;
  if (decomposeWordInDictionary(dictionary, target, 0, &result))
    return result;
}

// Solution 2: 
// Caching (Top down DP): cache if a valid decomposition
// for a prefix has been found O(n^2)
bool decomposeWordInDictionaryCache(const vector<string>& dictionary, const string& target, int prefix_idx, 
				    vector<string>* result, unordered_set<string>* cache) {
  if (prefix_idx >= target.size()) return true;
  if (cache->find(target.substr(0, prefix_idx)) != cache->end()) return false;

  for (const string& word : dictionary) {
    cout << word << " " << target.substr(prefix_idx, target.size() - prefix_idx) << endl;
    if (word.size() <= (target.size() - prefix_idx) &&
	word == target.substr(prefix_idx, word.size())) {
      result->emplace_back(word);
      if (decomposeWordInDictionaryCache(dictionary, target, prefix_idx + word.size(), result, cache)) {
	return true;
      }
      else {
	result->pop_back();
      }
    }
  }
  cache->emplace(target.substr(0,prefix_idx));
  return false;
}

vector<string> decomposeWordInDictionaryCache(const vector<string>& dictionary, const string& target) {
  vector<string> result;
  unordered_set<string> cache;
  decomposeWordInDictionaryCache(dictionary, target, 0, &result, &cache);
  return result;
}

int main(void) {
  //vector<string> dictionary = { "A", "B", "AB" };
  //string target("ABABC");
  vector<string> dictionary = { "a", "bad", "man", "can", "plan", "bat", "radar", "canal", "goal" };
  string target("amanaplanacanal");
  auto decomposition = decomposeWordInDictionary(dictionary,target);
}

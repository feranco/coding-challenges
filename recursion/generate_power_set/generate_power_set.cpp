//algorithm generating the power set of a set of items

#include <array>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void generatePowerSet(const vector<T>& items, vector<bool>* items_in_curr_power_set_ptr,
		      vector<vector<T>>* power_set) {

  vector<bool>& items_in_curr_power_set = *items_in_curr_power_set_ptr;

  if (items_in_curr_power_set.size() == items.size()) {
    vector<T> curr_power_set;
    for (int i = 0; i < items.size(); ++i) {
      if (items_in_curr_power_set[i]) curr_power_set.emplace_back(items[i]);
    }
    power_set->emplace_back(curr_power_set);
  }
  else 
    { 
      const array<bool, 2> in_out{ {false,true} };
      for (int j = 0; j < in_out.size(); ++j) {
	items_in_curr_power_set.emplace_back(in_out[j]);
	generatePowerSet(items, items_in_curr_power_set_ptr, power_set);
	items_in_curr_power_set.pop_back();
      }
    }
}

template <typename T>
vector<vector<T>> generatePowerSet(const vector<T>& items) {
  vector<vector<T>> power_set;
  vector<bool> items_in_curr_power_set_ptr;
  generatePowerSet(items, &items_in_curr_power_set_ptr, &power_set);
  return power_set;
}

int main(void) {
  vector<char> items{ 'a','b','c','d' };
  auto permutations = generatePowerSet(items);
  for (auto permutation : permutations) {
    for (auto item : permutation) cout << item << " ";
    cout << "\n";
  }
}

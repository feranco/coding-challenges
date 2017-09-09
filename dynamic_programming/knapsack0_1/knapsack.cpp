//algorithm solving knapsack 01 problem
#include <iostream>
#include <vector>

using namespace std;

struct Item {
  int value;
  int weight;
};

int call = 0;
int knapsack (const vector<Item>& items, int capacity, int i, int max_value) {
  //cout << ++call << " " << capacity << " " << max_value << endl; 
  if (i == items.size()) return max_value;

  if (capacity-items[i].weight >= 0) {

    return max(knapsack(items, capacity-items[i].weight, i+1, max_value+items[i].value),
	       knapsack(items, capacity, i+1, max_value));

  }

  return  knapsack(items, capacity, i+1, max_value); 
}

int main (void) {
  vector<Item> items {{65,20},{35,8},{245,60},{195,55},{65,40},{150,70},{275,85},{155,25},
	              {120,30},{320,65},{75,75},{40,10},{200,95},{100,50},{220,40},{99,10}};
  cout << knapsackCache(items, 130, 0, 0, cache);
}

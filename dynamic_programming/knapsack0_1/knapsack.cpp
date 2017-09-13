//algorithm solving knapsack 01 problem
#include <iostream>
#include <vector>

using namespace std;

struct Item {
  int value;
  int weight;
};

int call = 0;
//Solution 1:
//Backtracking
int knapsack (const vector<Item>& items, int capacity, int i, int max_value) {
  //cout << ++call << " " << capacity << " " << max_value << endl; 
  if (i == items.size()) return max_value;

  if (capacity-items[i].weight >= 0) {

    return max(knapsack(items, capacity-items[i].weight, i+1, max_value+items[i].value),
	       knapsack(items, capacity, i+1, max_value));

  }

  return  knapsack(items, capacity, i+1, max_value); 
}

//Solution 2:
//Cache + Retrieving items in knapsacke
int knapsackCache (const vector<Item>& items, int capacity, int i, int max_value, vector<vector<int>>& cache, vector<vector<int>>& pick) {
  //cout << ++call << " " << capacity << " " << max_value << endl; 
  if (i == items.size()) return max_value;
  if (cache[i][capacity] != -1) {
    cout << i << " " << capacity << " " << cache[i][capacity] << endl;
    return cache[i][capacity];
  }
  if (capacity-items[i].weight >= 0) {
    int taken = knapsackCache(items, capacity-items[i].weight, i+1, max_value+items[i].value, cache, pick);
    int not_taken = knapsackCache(items, capacity, i+1, max_value, cache, pick);
    if (taken > not_taken) {
      pick[i][capacity] = 1;
      cache[i][capacity] = taken;
    }
    else {
      pick[i][capacity] = 0;
      cache[i][capacity] = not_taken;
    }

  }
  else  {
    cache[i][capacity] =  knapsackCache(items, capacity, i+1, max_value, cache, pick);
    pick[i][capacity] = 0;
  }
  return cache[i][capacity];
}

vector<int> itemsInKnapsack (const vector<Item>& items, vector<vector<int>>& pick) {
  int capacity = pick[0].size()-1;
  int item = 0;
  vector<int> items_in_knapsack;
  while (item < items.size()) {
    if (pick[item][capacity] == 1) {
      items_in_knapsack.push_back(item);
      capacity -= items[item].weight;
    }
    item++;
  }
  return  items_in_knapsack;
}

int knapsackCache (const vector<Item>& items, int capacity, int i, int max_value) {
  vector<vector<int>> cache(items.size(), vector<int>(capacity+1,-1)); //2d cache cache(index, capacity) = value
  vector<vector<int>> pick(items.size(), vector<int>(capacity+1,3)); //2d cache cache(index, capacity) = value
  int res = knapsackCache(items, capacity, i, max_value, cache, pick);
  #if 0
  //debug
  for (int i = 0; i < items.size(); ++i) {
    for (int j = 0; j < capacity+1; ++j) {
      cout << cache[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  for (int i = 0; i < items.size(); ++i) {
    for (int j = 0; j < capacity+1; ++j) {
      cout << pick[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  #endif
  auto items_in_knapsack = itemsInKnapsack(items,pick);
  for (auto item : items_in_knapsack) cout << item << " ";
  return res;
}

int main (void) {
  /*
  vector<Item> items {{65,20},{35,8},{245,60},{195,55},{65,40},{150,70},{275,85},{155,25},
	              {120,30},{320,65},{75,75},{40,10},{200,95},{100,50},{220,40},{99,10}};
  
  cout << knapsackCache(items, 130, 0, 0);
  */
  
  vector<Item> items {{10,5},{40,4},{30,6},{50,3}};
  
  cout << knapsackCache(items, 10, 0, 0);
  
  /*
  vector<Item> items {{3,2},{4,3},{5,4},{6,5}};
  
  cout << knapsackCache(items, 5, 0, 0);
  */
}

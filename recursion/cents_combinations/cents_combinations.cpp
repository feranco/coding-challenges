#include <iostream>
#include <vector>

using namespace std;

int centsCombinations (vector<int> combination, vector<int>& coins, int n) {
  static int cnt = 0;
  for (int cents : coins) {
    if ((n-cents) < 0) continue;
    if ((n-cents) == 0) {
      combination.push_back(cents);
      cnt++;
      //for (int x : combination) cout << x << " ";
      //cout << "\n";
      return cnt;
    }
    if ((n-cents) > 0) {
      combination.push_back(cents);
      centsCombinations(combination, coins, n-cents);
    }
  }
  return cnt;
}

int main(void) {
  vector<int> comb;
  vector<int> coins = {25, 10, 5, 1};
  cout << centsCombinations(comb, coins, 35);
}

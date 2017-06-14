#include <iostream>
#include <vector>

using namespace std;

int centsCombinations (vector<int> combination, int coins[], int idx, int n) {
  static int cnt = 0;
  for (int i = idx; i < 4; ++i) {
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
  int coins[] = {25, 10, 5, 1};
  cout << centsCombinations(comb, coins, 35);
}

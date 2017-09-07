//algorithm to count the possible point combinations to get a score

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//Solution:
//dp with table (bottom up): use a recurrence formula
//computing each result using the previous ones
//recurrence: table[i][j] = table[i-1][j] + table[i-1][j-plays[i]] + table[i-1][j-2*plays[i]] 
//table[0][0] = 1 otherwise
//O(n^2)
#if 0
int scoreCombinations(const vector<int>& plays, int score) {

  int combinations = 0;
  vector<vector<int>> table(plays.size(), vector<int>(score+1, 0));

  //fill the table when only 1 plays is used
  for (int i = 0; i < table[0].size(); i += plays[0]) table[0][i] = 1;

  for (int i = 1; i < plays.size(); ++i) {
    for (int j = 0; j < score; ++j) {
      for (int k = 0; (j - k*plays[i]) >= 0; ++k) {
	table[i][j] += table[i - 1][j - k*plays[i]];
      }
    }
  }
  return table[plays.size()-1][score];
}
#endif

//O(s) space
int scoreCombinationsOpt(const vector<int>& plays, int score) {

  int combinations = 0;
  vector<int> table(score+1, 0);

  //fill the table when only 1 plays is used
  for (int i = 0; i < table.size(); i += plays[0]) table[i] = 1;

  for (int i = 1; i < plays.size(); ++i) {
    for (int j = score; j >= 0; --j) {
      int res = 0;
      for (int k = 0; (j - k*plays[i]) >= 0; ++k) {
	res += table[j - k*plays[i]];
      }
      table[j] = res;
    }
  }
  return table.back();
}


int main(void) {
  vector<int> plays = { 2,3,7 };
  cout << scoreCombinationsOpt(plays, 12);
}

//1D Dynamic Programming
//algorithm to compute the longest increasing sequence of a vector<int>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//First Solution:
//recursion naive (backtracking)
//O(n^n)

//compute the lis ending at index i
int lisEndingHere(const vector<int>& sequence, int i) {
  //base case
  if (i == 0) return 1;
  int lis = 1;
  for (int j = 1; j < i; ++j) {
    if (sequence[j] < sequence[i]) lis = max(lis, lisEndingHere(sequence, j) + 1);
  }
  return lis;
}

int lisBacktracking(const vector<int>& sequence) {

  int lis = 0;
  for (int i = 0; i < sequence.size(); ++i) {
    lis = max(lis, lisEndingHere(sequence, i));
  }
  return lis;
}

//Second Solution:
//dp with caching (top down): modify the previous solution caching the 
//partial results
//O(n^2)

int lisEndingHere(const vector<int>& sequence, int i, vector<int>& cache) {
  //base case
  if (i == 0) return 1;
  int lis = 1;
  for (int j = 0; j < i; ++j) {
    if (sequence[j] < sequence[i]) {
      if (cache[j] < 0) cache[j] = lisEndingHere(sequence, j,cache);
      lis = max(lis, cache[j]+1);
    }
  }
  return lis;
}

int lisCaching(const vector<int>& sequence) {

  int lis = 0;
  vector<int> cache(sequence.size(), -1);
  for (int i = 0; i < sequence.size(); ++i) {
    //per ogni elemento calcolo la lis che finisce li e alla fine prendo il max
    lis = max(lis, lisEndingHere(sequence, i, cache));
  }
  return lis;
}

//Third Solution:
//dp with table (bottom up): use a recurrence formula
//computing each result using the previous ones
//recurrence: lis[i] = max(lis[j]+1) if lis[j] < lis[i] exists
// lis[i] = 1 otherwise
//O(n^2)

int lisTabular(const vector<int>& sequence) {

  int lis = 1;
  vector<int> table(sequence.size(), -1);
  for (int i = 0; i < sequence.size(); ++i) {
    int lis_ending_here = 1;
    for (int j = 0; j < sequence.size(); ++j) {
      if (sequence[j] < sequence[i]) lis_ending_here = max(lis_ending_here, table[j] + 1);
    }
    table[i] = lis_ending_here;
    lis = max(lis, lis_ending_here);
  }
  return lis;
}



int main(void) {
  //vector<int> sequence = { 2,4,3,5 };
  vector<int> sequence = { 2,4,3,5 , 1, 7, 6, 9, 8 };
  cout << lisTabular(sequence);
}

/*
  There is a rod of length N lying on x-axis with its left end at x = 0 and right end at x = n. 
  There are m weak points on this rod denoted by positive integer values (all less than n). 
  The rod sall be cut at all these weak points, minimizing the total cost. 
  The cost of making a cut is the length of the sub-rod in which the cut is made. 
  The cuts can be performed  in any order. 
  Return an array denoting the sequence in which the cuts are made. 
  If two different sequences of cuts give same cost, return the lexicographically smallest.
*/

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//Solution 1: memoization
int rodCutAux(int l, int r, vector<int> &cuts, vector<vector<int>>* dp, vector<vector<int>>* min_cuts) {

  //sub-rod without weak point can't be cut
  if (r-l <= 1) return 0;
    
  //check if sub-rod cost has been already found
  if((*dp)[l][r] != -1) return (*dp)[l][r];
    
  int min_cost = numeric_limits<int>::max();
  //check weak point inside sub-rod
  for (int i = l+1; i < r; ++i) {
    int cost = 0;
    int v = rodCutAux(l, i, cuts, dp, min_cuts);
    int w = rodCutAux(i, r, cuts, dp, min_cuts);
    cost += (cuts[r]-cuts[l]) + v + w;
    if (cost < min_cost) {
      //update sub-rod min-cost and index giving min-cost
      min_cost = cost;
      (*min_cuts)[l][r] = i;
    }        
  }
  (*dp)[l][r] = min_cost;
  return min_cost;
}

void minCuts (int l, int r, const vector<int>& cuts, const vector<vector<int>>& min_cuts, vector<int>& result) {
  if ((r-l) < 2) return;
  int min_cut_idx = min_cuts[l][r];
  result.push_back(cuts[min_cut_idx]);
  minCuts(l, min_cut_idx,cuts, min_cuts,result);
  minCuts(min_cut_idx,r,cuts, min_cuts,result);
}

vector<int> rodCut(int n, const vector<int>& cuts) {
  //cuts bounded by the begin (0) and the end of the rod (n)
  vector<int> bounded_cuts{0};
  for (int x : cuts)  bounded_cuts.push_back(x);
  bounded_cuts.push_back(n);
  //dp matrix to store minimum cost for each sub-road
  vector<vector<int>> dp(bounded_cuts.size(),vector<int>(bounded_cuts.size(),-1));
  //dp matrix to store the (index of) the cut giving the minimum cost for each sub-rod 
  vector<vector<int>> min_cuts(bounded_cuts.size(),vector<int>(bounded_cuts.size(),-1));
  //solve the problem
  rodCutAux(0, bounded_cuts.size()-1, bounded_cuts, &dp, &min_cuts);
  //get the sequence of minimum cuts
  vector<int> result;
  minCuts(0,dp.size()-1,bounded_cuts,  min_cuts, result);
  return result;
}

#if 0
//Solution 2: tabular
vector<int> rodCut(int n, const vector<int>& cuts) {
    
  //cuts bounded by the begin (0) and the end of the rod (n)
  vector<int> bounded_cuts{0};
  for (int x : cuts)  bounded_cuts.push_back(x);
  bounded_cuts.push_back(n);
  //dp matrix to store minimum cost for each sub-road
  vector<vector<int>> dp(bounded_cuts.size(),vector<int>(bounded_cuts.size(),-1));
  //dp matrix to store the (index of) the cut giving the minimum cost for each sub-rod 
  vector<vector<int>> min_cuts(bounded_cuts.size(),vector<int>(bounded_cuts.size(),-1));
    
  vector<vector<pair<long long, int> > > memo(size, vector<pair<long long, int> >(size, make_pair(0, -1)));

  // Fill dp table based on the number of cuts 
  for(int n_cuts = 0; n_cuts < bounded_cuts.size()-1; n_cuts++) {
    //Set begin and end of sub-rod given the number of cuts
    for (i = n_cuts+1; i < bounded_cuts.size(); i++) {
      // start = i-l-1, end = i;
      int l = i-n_cuts-1;
      int r = i;

      if (n_cuts == 0) {
	dp[s][e] = 0;
	min_cuts[s][e] = -1;
      }
      else {
	// k = start+1 to end-1
	int min_cost = numeric_limits<int>::max(); 
	//compute the cost for each weak point between l and r
	for (k = l+1; k < r; k++) {
	  int cost = dp[l][k] + dp[k][r];
	  if (min_cost > cost) {
	    min_cost = cost;
	    min_cuts[l][r] = k;
	  }
	}
	dp[l][r] = bounded_cuts[r]-bounded_cuts[l] + min_cuts;
      }
    }
  }
}
#endif

int main (void) {
  vector<int> a{2, 4, 6};
  rodCut(7,a);
}

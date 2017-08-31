//algorithm generating all the possible placements of n queens in a nxn chessboard
//1) since two or more queens must be in different rows, a placement is coded
//with a vector of size n: each element represent the position of the queen in the corresponding row

#include <iostream>
#include <vector>

using namespace std;

bool isValidPlacement (const vector<int>& curr_placement) {
  int idx_last = curr_placement.size()-1;
  for (int i = 0; i < idx_last; ++i) {
    if (curr_placement[idx_last] == curr_placement[i] ||
	curr_placement[idx_last] == (curr_placement[i] - (idx_last - i)) ||
	curr_placement[idx_last] == (curr_placement[i] + (idx_last - i)))
      return false;	
  }
  return true;
}

void queenPlacementsHelper (int n, vector<int>* curr_placement, vector<vector<int>>* placements) {

  //if is a solution, process solution
  if (curr_placement->size() == n) {
		placements->emplace_back(*curr_placement);
	} 
	else {	//this else is important in order to not exceed the search space (placement with >n queens)
		for (int i = 0; i < n; ++i) {//construct candidate and cycle over them
			curr_placement->push_back(i);//make move
			if (isValidPlacement(*curr_placement)) {//prune not valid candidates
				queenPlacementsHelper(n, curr_placement, placements);
			}
			curr_placement->pop_back();//unmake move
		}
  }
}

//each placement can be represented as a vector of int
//each element is the position of the queen in the corresponding row
vector<vector<int>> queenPlacements (int n) {
  vector<vector<int>> placements;//solution vector
  vector<int> curr_placement;
  queenPlacementsHelper(n, &curr_placement, &placements);
  return placements;
}

int main(void) {
  auto placements = queenPlacements (4);
  for (auto placement : placements) {
    for (auto queen : placement) cout << queen << " ";
    cout << "\n";
  }
}

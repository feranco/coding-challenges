//algorithm to count the possible point combinations to get a score

#include <array>
#include <iostream>
#include <unordered_map>

using namespace std;

int scoreCombinations (const array<int,3>& points, int score, unordered_map<int,int>* score_to_combinations_ptr) {
  //base case
  if (score < points[0]) return 0;
  unordered_map<int,int>& score_to_combinations = *score_to_combinations_ptr;
  if (score_to_combinations.find(score) == score_to_combinations.end()) {
    score_to_combinations[score] =
      scoreCombinations(points, score-points[0], score_to_combinations_ptr) +
      scoreCombinations(points, score-points[1], score_to_combinations_ptr) +
      scoreCombinations(points, score-points[2], score_to_combinations_ptr);
  }
  return score_to_combinations[score];
}

int scoreCombinations (const array<int,3>& points, int score) {
  unordered_map<int,int> score_to_combinations;
  for (int point : points) score_to_combinations[point] = 1;
  return scoreCombinations (points, score, &score_to_combinations);
}

int main (void) {
  array<int,3> points{{2,3,7}};
  cout << scoreCombinations(points,12);
}

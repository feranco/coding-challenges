// algorithm to generate all configuration of n matched brackets
// backtracking
#include <iostream>
#include <vector>

using namespace std;

//check is a solution
bool isMatchedBrackets(int left, int right) {
  return (left == 0 && right == 0);
}

//generate candidate brackets
vector<string> generateNextBrackets(int left, int right) {
  if (left == right && left > 0) return {"("};
  else if (left < right && left == 0) return {")"};
  else if (left < right && left > 0) return {"(",")"};
  else return {};
}

void generateMatchedBrackets(vector<vector<string>>* matched_brackets, vector<string>* curr_brackets,
			     int left, int right) {
	
  if (isMatchedBrackets(left, right)) matched_brackets->emplace_back(*curr_brackets);
  else {
    auto next_brackets = generateNextBrackets(left, right);
    for (auto bracket : next_brackets) {
      //make move
      curr_brackets->emplace_back(bracket);
      (bracket == "(") ? left-- : right--;
      generateMatchedBrackets(matched_brackets, curr_brackets, left, right);
      //unmake move
      curr_brackets->pop_back();
      (bracket == "(") ? left++ : right++;
    }
  }
}

vector<vector<string>> generateMatchedBrackets (int n) {
  vector<vector<string>> matched_brackets;
  vector<string> curr_bracket;
  generateMatchedBrackets(&matched_brackets, &curr_bracket, n, n);
  return  matched_brackets;
}

int main(void) {
  auto matched_brackets = generateMatchedBrackets (4);
  for (auto matched_bracket : matched_brackets) {
    for (auto bracket : matched_bracket) cout << bracket;
    cout << "\n";
  }
}

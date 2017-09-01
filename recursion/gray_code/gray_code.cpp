//algorithm generating a n-bit gray code 

#include <array>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int getOnes (int n) {
  int ones = 0;
  while (n != 0) {
    ones += (n & 1);
    n = n >> 1;
  }
  return ones;
}

bool isPossibleKeyword (int new_keyword, int prev_keyword) {
  int xor_keyword = new_keyword ^ prev_keyword;
  if (getOnes(xor_keyword) == 1) return true;
  return false;
}

vector<int> computeKeywords(int n, const vector<int>& gray_code) {
  vector<int> result;
  for (int i = 0; i < n; ++i) {
    //possible optimization: use hash set instead of find
    if (gray_code.size() == 0 || (isPossibleKeyword(i,gray_code.back()) && find(gray_code.begin(), gray_code.end(), i) == gray_code.end())) 
      result.emplace_back(i);
  }
  return result;
}

//n = number of possible keywords
void computeGrayCode(int n, vector<int>* gray_code, bool* finished) {
  if (gray_code->size() == n) {
    {//the first keyword shall be possible considering the last one
    if (isPossibleKeyword(0,gray_code->back())) 
    *finished = true;
    return;
    }
  }
  else {
    auto possible_keywords = computeKeywords(n, *gray_code);
    for (auto keyword :  possible_keywords) {
      gray_code->emplace_back(keyword);
      computeGrayCode(n, gray_code, finished);
      if (*finished) return;
      gray_code->pop_back();
    }
  }
}

//n = number of bits
vector<int> computeGrayCode(int n) {
  vector<int> gray_code;
  bool finished = false;
  computeGrayCode(pow(2,n), &gray_code, &finished);
  return gray_code;
}

int main(void) {
  auto code = computeGrayCode(3);
  for (auto keyword : code) {
    cout << keyword << " ";
  }
}

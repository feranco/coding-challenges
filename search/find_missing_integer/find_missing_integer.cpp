//algorithm to find the missing integers in a file
//Assumptions:
//1) integers are not required to be sorted
//2) consume as few memory as possible
//O(n) time, 250KB for 32 bit integers, 128B for 8 bit integers (as in the test)

#include <fstream>
#include <algorithm>
#include <vector>

using std::ifstream;
using std::vector;

vector<int> findMissingIntegers(ifstream& ifs) {
  const int half_size = 4;// 16;
  vector<size_t> counter(1 << half_size, 0);
  unsigned int current;

  //for each integer increase the bucket corresponding to its msb
  while (ifs >> current) ++counter[current >> half_size];

  vector<int> candidates_msb, result;

  for (size_t i = 0; i < counter.size(); ++i) {
    if (counter[i] < counter.size()) candidates_msb.push_back(i);
  }

  for (int candidate : candidates_msb) {
    //go back to the first integer
    ifs.clear();
    ifs.seekg(0);

    //reset counter
    std::fill(counter.begin(), counter.end(), 0);

    //for each integer increase the bucket corresponding to its lsb
    while (ifs >> current) {
      if ((current >> half_size) == candidate) ++counter[current & ((1 << half_size) - 1)]; //(0xF = 1 << half) -1
    }

    for (size_t i = 0; i < counter.size(); ++i) {
      if (!counter[i]) {
	result.push_back(((candidate << half_size) | i));
      }
    }

  }

  return result;
}

int main(void){
  ifstream file{"integers.txt"};
  if (file) {
    auto missing = findMissingIntegers(file);
    file.close();
  }
}

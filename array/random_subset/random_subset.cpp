//algorithm to select a random subset of size k from an array 
//Assumptions;
//1) the k elements of the subset are put in the first k positions;

#include <array>
#include <iostream>
#include <random>

using std::cout;
using std::endl;
using std::array;

template <std::size_t SIZE = 10>
void randomSubset (array<char, SIZE>* a_ptr, int k) {
  array<char, SIZE>& a = *a_ptr;
  std::default_random_engine ran{};
  for (int i = 0; i < k; ++i) {
    std::swap(a[i], a[std::uniform_int_distribution<int>{i,static_cast<int>(a.size()-1)}(ran)]);
  }
     
}

int main (void) {
    array<char,5> a {{'a','b','c','d','e'}};
    randomSubset(&a,2);
    for (auto x : a) cout << x;
}

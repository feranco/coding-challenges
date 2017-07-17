//algorithm to apply a permutation to an array in place
//Assumptions;
//1) permutation is specified by an array of indices;
//2) the permuted array contains character

#include <iostream>
#include <array>
#include <algorithm>

using std::cout;
using std::endl;
using std::array;

template<std::size_t SIZE>
bool isPermuted(int idx, const array<int, SIZE>& p) {
    if (p[idx] == idx) return true;
    for (int i = p[idx]; i != idx; i = p[i]) {
        if (i < idx) return true;
    }
    return false;
}

template<std::size_t SIZE>
void applyPermutation(array<char, SIZE>* a_ptr, const array<int, SIZE>& p) {
    array<char, SIZE>& a = *a_ptr;
    for (int i = 0; i < a.size(); ++i) {
        if (isPermuted(i, p)) continue;
        char tmp = a[p[i]];
        a[p[i]] = a[i];
        for (int j = p[p[i]]; j != p[i]; j = p[j]) {
            std::swap(tmp, a[j]);
        }
    }
}

int main (void) {
    array<char,5> a {{'a','b','c','d','e'}};
    array<int, 5> p {{2,0,4,3,1}};
    applyPermutation(&a,p);
    for (auto x : a) cout << x;
}

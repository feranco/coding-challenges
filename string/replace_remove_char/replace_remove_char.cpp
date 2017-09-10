//algorithm to replace each 'a' with two 'd' and delete each 'b'
//Assumptions:
//1) number of character in input is given (size)
//2) there is enough space to contain the result
//O(n)

#include <iostream>

using namespace std;

int replace_remove(char* a, int size) {
  int n_a = 0, w = 0;
  //count a occurrence and cancel b (forward)
  for (int i = 0; i < size; ++i) {
    if (a[i] == 'a') ++n_a;
    if (a[i] != 'b') {
      a[w++] = a[i];
    }
  }
  
 w = (w-1) + n_a;
 const int new_size = w-1;

 //replace a with d (backward)
 for (int r = w+1-n_a; r >= 0; --r) {
    if (a[r] == 'a') {
      a[w--] = 'd';
      a[w--] = 'd';
    }
    else {
      a[w--] = a[r];
    }
  }
 return new_size;
}

int main (int argc, char *argv[]) {
  char* s = argv[1];
  int size = atoi(argv[2]);
  
  int new_size = replace_remove(s, size);
  
  for (int i = 0; i < new_size; ++i) {
    cout << s[i];
  }
}

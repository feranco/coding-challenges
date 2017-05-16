#include <iostream>

int bitsToFlip (int a, int b) {
  const int mask = 1;
  int cnt = 0;
  //int c = a^b;
  for (int c = a^b; c != 0; c>>=1) {
    if (c & mask) cnt++;
  }
  return cnt;
}

int main (int argc, const char* argv[]) {
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int c = bitsToFlip(a, b);
  std::cout << a << " " << b << " flip " << c;
} 

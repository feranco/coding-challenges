#include <iostream>
#include <cstring>

using std::cout;

const int diff = 2; //difference between "%20" and ' '
//const char pattern[] = "%20";

void replaceSpaces (char* s, int len) {
  
  int spaces = 0;
  //count spaces
  for (int i = 0; i < len; ++i) if (s[i] == ' ') spaces++;

  int w_pos = (len-1) + (spaces * diff);
  s[w_pos+1] = '\0';

  for (int i = len-1; i >= 0; i--) {
    if (s[i] != ' ') s[w_pos--] = s[i];
    else {
      //for (int i = 2; i >= 0; --i) s[w_pos--] = pattern[i];
      
      strncpy(&s[w_pos-diff], "%20", 3);
      w_pos-=3;
      
    }
  }
}

int main (int argc, char* argv[]) {
  char s[] = " Mr John Smith          ";
  replaceSpaces(s,14);
  int len =  strlen(s);
  for (int i = 0; i < len; ++i) {
    cout << s[i];
  }
}

#include <iostream>
#include <stdexcept>
#include <cstring>

using std::cout;
using std::endl;

static char letters [8] [3] = {
  {'A', 'B', 'C'},
  {'D', 'E', 'F'},
  {'G', 'H', 'I'},
  {'J', 'K', 'L'},
  {'M', 'N', 'O'},
  {'P', 'R', 'S'},
  {'T', 'U', 'V'},
  {'W', 'X', 'Z'}
};

char getCharKey (int key, int place) {
  //cout << key << " " << place;
  if (key < 2 || key > 9) throw std::invalid_argument("key not valid");
  if (place > 2) throw std::invalid_argument("keyplace not valid");
  return letters[key-2][place];
};

const int num_length = 3;

void telephoneNumber (int digits[]) {
  int i, idx[num_length];
  char out[num_length+1];

  for (i = 0; i < num_length; ++i) {
    //cout << digits[i];
    idx[i] = 0;
    out[i] = getCharKey(digits[i],idx[i]);
  }
  out[i] = '\0';

  while(1) {
    cout << out << endl;
    for (i =  num_length-1; i >= -1; --i) {
      if (i < 0) return;
      if (digits[i] > 1) {
	idx[i] = (++idx[i]%3);
	out[i] = getCharKey(digits[i],idx[i]);
	if (idx[i] != 0) break;
      }
    }
  }
}

int main (int argc, const char* argv[]) {
  // Prints each argument on the command line.
  int number[num_length] = {8,6,6};//,2,6,6,5};
  
  for( int i = 1; i < argc; i++ ) {
    cout << number[i];
    //printf( "arg %d: %s\n", i, argv[i] );
    //number[i] = atoi(&argv[i]);
    }
  telephoneNumber(number);
}


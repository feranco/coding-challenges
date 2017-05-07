#include <string>
#include <iostream>

using std::string;
using std::cout;

void permutationR (string in, string out, bool used[]) {
  if (in.size() == out.size()) {
    cout << out << "\n";
    return;
  }

  for (int i = 0; i < in.size(); ++i) {
    if (!used[i]) {
      used[i] = true;
      out.append(in,i,1);
      permutationR(in, out, used);
      used[i] = false;
      out.resize(out.size()-1);
    }
  }
}

void permutation (string in) {
  string out;
  bool* used = new bool[in.size()];
  permutationR(in, out, used);
  delete[] used;
}

int main (int argc, const char* argv[]) {
  // Prints each argument on the command line.
  for( int i = 0; i < argc; i++ )
    {
      printf( "arg %d: %s\n", i, argv[i] );
    }
  permutation(argv[1]);
}

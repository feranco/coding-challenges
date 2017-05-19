#include <iostream>
#include <string>

using std::cout;
using std::string;
#if 0
int stringSearch (const string a[], int l, int r, const string& str) {
  if (r < l) return -1;

  int m = (l+r) / 2;
  if (a[m] == "") {
    int i, j;
    for (i = m, j = m; (i >= l && j <= r && a[i] == "" && a[j] == ""); --i, ++j);
    if (i >= l && a[i] != "") m = i;
    if (j <= r && a[j] != "") m = j;
  } 

  if (a[m] == "") return -1;

  if (a[m] == str) return m;
  if (str < a[m]) return stringSearch(a, l, m-1, str);
  else return stringSearch(a, m+1, r, str);
}
#endif

int stringSearch (const string a[], int l, int r, const string& str) {

  while (r >= l) {
    int m = (l+r) / 2;
    if (a[m].empty()) {
      int i, j;
      for (i = m, j = m; (i >= l && j <= r && a[i].empty() && a[j].empty()); --i, ++j);
      if (i >= l && !a[i].empty()) m = i;
      if (j <= r && !a[j].empty()) m = j;
  } 

  if (a[m].empty()) return -1;
  if (a[m].compare(str) == 0) return m;
  if (a[m].compare(str) < 0) r = m-1;
  else l = m+1;
}
return -1;
}

int main (void) {
  string a[] = {"asso","","","","balla","","","","","","fifa","rossa","",""};
  cout << stringSearch(a, 0, 13, "balla");
  string b[] = {"asso","","","","balla","","","","","","fifa","rossa","",""};
  cout << stringSearch(b, 0, 13, "balli");
  string c[] = {"","","","","","","","","","","","","",""};
  cout << stringSearch(c, 0, 13, "balli");
  string d[] = {"","","","","","","","","","","","","","balli"};
  cout << stringSearch(d, 0, 13, "balli");
  string e[] = {"balli","","","","","","","","","","","","",""};
  cout << stringSearch(e, 0, 13, "balli");
}

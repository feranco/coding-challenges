#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getValidBrackets(vector<string>& brackets, string expr, int opened, int closed, int n) {

  if (opened == n && closed == n) { brackets.push_back(expr); return; }

  if (opened == closed) { expr.append("("); getValidBrackets(brackets, expr, opened + 1, closed, n);  return; }
  if (opened == n && closed < n) { expr.append(")"); getValidBrackets(brackets, expr, opened, closed + 1, n);  return; }
  if (opened > closed) {
    getValidBrackets(brackets, expr.append("("), opened + 1, closed, n);//opened > closed ¦¦ opened == closed
    expr.pop_back();
    getValidBrackets(brackets, expr.append(")"), opened, closed + 1, n);//opened > closed ¦¦ opened == n && closed < n
  }
}

//improvement: 1) add an if to check invalid conditions (opened < closed || opened > n)
//2) call recursively getValidBrackets only twice: one if opened < n and one for close < n 

int main(void) {
  vector<string> brackets;
  getValidBrackets(brackets, "", 0, 0, 4);
  for (string s : brackets) cout << s << "\n";
}

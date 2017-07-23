//algorithm to evaluate rpn expressions
//assumptions:
//1) operand are integers
//2) operand and operators in input string are comma separated
//O(n) time, O(n) space


#include <iostream>
#include <sstream>
#include <stack>

using std::cout;
using std::stack;
using std::stringstream;
using std::string;

int evaluateSingleExpr (int op1, int op2, const string& op) {
  int res = 0;
  if (op == "+") res = op1 + op2;
  if (op == "-") res = op1 - op2;
  if (op == "*") res = op1 * op2;
  if (op == "/") res = op1 / op2;
  return res;
}

int evaluateRPN (const string& rpn_expr) {
  string current_op;
  stack<int> s;
  stringstream ss(rpn_expr);

  while (getline(ss, current_op, ',')) {
      if (current_op == "+" || current_op == "-" ||
	  current_op == "*" || current_op == "/" ) {
	const auto op1 = s.top();
	s.pop();
	const auto op2 = s.top();
	s.pop();
	s.push(evaluateSingleExpr(op1, op2, current_op));
      }
      else s.push(stoi(current_op)); 
    }
    return s.top();
    }

int main (void) {
  string rpn = "3,4,+,2,*,1,+";
  cout << evaluateRPN(rpn);
}

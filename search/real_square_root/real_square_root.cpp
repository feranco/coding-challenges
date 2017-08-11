//algorithm to compute the root square of a double
//assumptions:
//1) use of sqrt is not allowed
//O(log(n)) time O(1)space

#include <cmath>
#include <iostream>
#include <stdexcept>

using std::cout;
using std::abs;

double squareRoot(double n, double threeshold = 0.001) {
	double l = 0, r = (n < 1) ? 1 : n, m = n;
	if (m < 0) std::runtime_error("input is negative");
	while (l <= r) {
		m = l + ((r - l) / 2);
		double square = m*m;
		if (abs(square - n) < threeshold) break;
		if (square < n) l = m;
		else r = m;
	}
	return m;
}

int main(void) {
	cout << squareRoot(21) << std::endl;
	cout << squareRoot(0.5);
}

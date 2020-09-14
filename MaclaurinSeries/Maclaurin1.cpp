#include <iostream>
#include <cmath>
using namespace std;

/*
Maclaurin series of f(x) = exp(2x)
take advantage of the fact that (n+1)th term = nth term * 2*x/(n+1)

*/

int main() {
	int n = 100; // nums of iteration
	int x = -10; //exponent value
	double expval[120] = {}; //starting value = 1
	double curTerm; // current term, where to start the simulation
	double trueValue = exp(2 * x);
	double rel_err; // relative error
	double abs_err; // absolute error 
	double tol = 1e-8; //tolerance


	for (int i = 1; i <= n; i++) {
		curTerm = ( 2 * x )/ i;
		expval[i+1] = 1 + curTerm;
		rel_err = abs(trueValue - expval[i+1]) / abs(trueValue);
		abs_err = abs(trueValue - expval[i+1]);

		if (expval[i+1] == expval[i]) {
			break;
		}
		cout << "It needs " << i << " iterations to converge." << endl;
	}
	return 0;
}

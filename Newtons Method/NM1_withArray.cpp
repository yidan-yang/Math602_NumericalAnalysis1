#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>
using std::setw;


/* f(x) is a hyperbola*/
double obj_f(double x) {
	double result;
	result = x * (1 + 10 / (1 + x)) - 1;
	return result;
}

double obj_df(double x) {
	double result = 1 + 10 / ((1 + x) * (1 + x));
	return result;
}


/* Array stores x in each iteration*/
int main() {
	/* Newton Method to find the root of f
		% obj_f: original function
		% obj_df : derivative of original function by a given value x
		% x[0] : initial value
		% tol : max error
		% MaxIter : max iteration */
	int MaxIter;
    cout << "Maximum Iteration: ";
	cin >> MaxIter;

	double initialValue;
	cout << "Initial Value: " ;
	cin >> initialValue;

	double x[1000] = {};
	x[0] = initialValue;
	double tol = 1e-8;
	double result;

	//double err[100];

	for (int i = 0; i <= MaxIter; i++) {
		x[i + 1] = x[i] - obj_f(x[i]) / obj_df(x[i]);
		if (abs(x[i + 1] - x[i]) < tol) {
			result = x[i];
			cout << "The root is: " << result;
			break;
		}
		if (i == MaxIter) {
			cout << "No solution in " << MaxIter <<" iterations.";
		}
	}
}

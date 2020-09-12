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



/* Overlap each iteration*/
int main() {
	int MaxIter;
	cout << "Maximum Iteration: ";
	cin >> MaxIter;

	double initialValue;
	cout << "Initial Value: ";
	cin >> initialValue;

	double x;
	x = initialValue;
	double tol = 1e-8;
	double result;

	//double err[100];

	for (int i = 0; i <= MaxIter; i++) {
		x = x - obj_f(x) / obj_df(x);
		if (obj_f(x) < tol) {
			result = x;
			cout << "The root is: " << result;
			break;
		}
		if (i == MaxIter) {
			cout << "No solution in " << MaxIter << " iterations.";
		}
	}
}

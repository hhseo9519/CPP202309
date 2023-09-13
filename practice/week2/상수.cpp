#include <iostream>
#include <string>
using namespace std;

int main() {
	int income = 1000;
	const double TAX_RATE = 0.25;
	income = income - TAX_RATE * income;

	double x = 100;
	x = x * PI;
	PI = 15454;

	cout << x << endl;
	return 0;
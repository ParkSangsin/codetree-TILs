#include<iostream>
using namespace std;

int main() {
	double a, b;

	cin >> a >> b;

	cout << fixed;
	cout.precision(2);
	cout << a + b;
	return 0;
}
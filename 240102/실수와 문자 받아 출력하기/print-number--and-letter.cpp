#include<iostream>
#include<string>
using namespace std;

int main() {
	string a;
	double b, c;

	cin >> a >> b >> c;

	cout << fixed;
	cout.precision(2);
	cout << a << "\n" << b << "\n" << c;
	return 0;
}
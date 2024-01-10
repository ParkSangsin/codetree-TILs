#include <iostream>
using namespace std;

int main() {

	int a, kg;
	cin >> a >> kg;

	double cm = double(a) / 100;
	cm *= cm;

	int bmi = kg / cm;

	cout << bmi << endl;
	if (bmi > 25) {
		cout << "Obesity";
	}

	return 0;
}
#include <iostream>
using namespace std;

int main() {
	int a;

	cin >> a;

	if (a % 2 == 0) {
		if (a < 8) {
			cout << 31;
		}
		else {
			cout << 30;
		}
	}
	if (a % 2 == 1) {
		if (a == 2) {
			cout << 28;
		}
		else if (a < 8) {
			cout << 31;
		}
	}


	return 0;
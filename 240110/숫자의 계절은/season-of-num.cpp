#include <iostream>
using namespace std;

int main() {
	int a;

	cin >> a;

	if (3 <= a && a <= 5) {
		cout << "Spring";
	}
	else if (6 <= a && a <= 8) {
		cout << "Summer";
	}
	else if (9 <= a && a <= 11) {
		cout << "Fall";
	}
	else if (12 == a || 1 <= a && a <= 2) {
		cout << "Winter";
	}


	return 0;
}
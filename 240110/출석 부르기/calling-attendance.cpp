#include <iostream>
using namespace std;

int main() {
	int a;
	
	cin >> a;

	if (a == 1) {
		cout << "John";
	}
	else if (a == 2) {
		cout << "Tom";
	}
	else if (a == 3) {
		cout << "Paul";
	}
	else {
		cout << "Vacancy";
	}
	return 0;
}
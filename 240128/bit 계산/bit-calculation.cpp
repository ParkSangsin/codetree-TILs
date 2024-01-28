#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define MAX_N 2000

int q;

int snum; // 집합 S: x가 존재한다면 2^x을 더해준다. (비트를 킴)

int main() {
	cin >> q;

	for (int t = 0; t < q; t++) {
		string str;
		int x;
		cin >> str;

		if (str == "add") {
			cin >> x;
			snum |= (1 << x); // x번 비트를 켜라
		}
		else if (str == "delete") {
			cin >> x;
			snum &= ~(1 << x); // x번 비트를 꺼라
		}
		else if (str == "print") {
			cin >> x;
			if ((snum & (1 << x)) != 0) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (str == "toggle") {
			cin >> x;
			if ((snum & (1 << x)) != 0) {
				snum &= ~(1 << x); // x번 비트를 꺼라
			}
			else {
				snum &= ~(1 << x); // x번 비트를 꺼라
			}
		}
		else if (str == "clear") {
			snum = 0;
		}
	}

	return 0;
}
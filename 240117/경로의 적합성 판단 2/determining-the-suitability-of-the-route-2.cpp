#include <iostream>

using namespace std;

#define MAX_N 100000

int n, m, k; // 정수 개수, 연산 횟수
int uf[MAX_N + 1];

int find(int x) {
	if (uf[x] == x) {
		return x;
	}
	uf[x] = find(uf[x]);
	return uf[x];
}

void union_(int a, int b) {
	a = find(a);
	b = find(b);

	uf[a] = b;
}

int main() {
	cin >> n >> m >> k;

	// 유니온 파인드를 위한 초기 값 설정
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
	}

	// 합치기
	while (m--) {
		int x, y;
		cin >> x >> y;
		union_(x, y);
	}

	int a, b;
	cin >> a;
	int flag = 1;

	while (k--) {
		cin >> b;
		if (find(a) != find(b)) {
			flag = 0;
		}
		a = b;
	}

	if (flag) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}
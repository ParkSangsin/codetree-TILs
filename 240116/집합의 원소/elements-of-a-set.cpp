#include <iostream>

using namespace std;

#define MAX_N 100000

int n, m; // 정수 개수, 연산 횟수
int uf[MAX_N + 1];

int find(int x) {
	if (uf[x] == x) {
		return x;
	}
	uf[x] = find(uf[x]);
	return uf[x];
}

void uni(int a, int b) {
	int root_a = find(a);
	int root_b = find(b);

	uf[root_a] = root_b;
}

int main() {
	cin >> n >> m;

	// 유니온 파인드를 위한 초기 값 설정
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
	}

	while (m--) {
		int q, a, b;
		cin >> q >> a >> b;
		if (q == 0) {
			uni(a, b);
		}
		else {
			if (find(a) == find(b)) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}

	}
}
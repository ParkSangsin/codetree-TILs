#include <iostream>

using namespace std;

#define MAX_N 100000

int n, m, k; // 정수 개수, 연산 횟수
char q;
int a, b;
int uf[MAX_N + 1];
int child[MAX_N + 1];

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

	if (a != b) {
		uf[a] = b;
		child[b] += child[a];
	}
}

int main() {
	cin >> n >> m;

	// 유니온 파인드를 위한 초기 값 설정
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
		child[i] = 1;
	}

	while (m--) {
		cin >> q;
		if (q == 'x') {
			cin >> a >> b;
			union_(a, b);
		}
		else {
			int cnt;
			cin >> a;
			cout << child[find(a)] << endl;
		}
	}
}
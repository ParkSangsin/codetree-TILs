#include <iostream>

using namespace std;

#define MAX_N 100000

int n;
char q;
int a, b;
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
	cin >> n;

	// 유니온 파인드를 위한 초기 값 설정
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
	}

	for (int i = 0; i < n - 2; i++) {
		cin >> a >> b;
		union_(a, b);
	}

    // 1번 노드와 떨어져 있는 점 중 번호가 가장 작은 정점
	for (int i = 2; i <= n; i++) {
		if (find(1) != find(i)) {
			cout << 1 << " " << i;
			break;
		}
	}
}
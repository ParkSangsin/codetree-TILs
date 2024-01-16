#include <iostream>

using namespace std;

#define MAX_N 100000

int n, m;
char q;
int a, b;
int uf[MAX_N + 1];
int cnt; // 사이클이 없을 때, 없애기 위해 자르는 연산이 필요한 횟수

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
	cin >> n >> m;

	// 유니온 파인드를 위한 초기 값 설정
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
	}

	int res;
	int flag = true;

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		// 두 점의 루트가 다르다면 (사이클이 생기지 않을 경우)
		if (find(a) != find(b)) {
			cnt++;
			union_(a, b);
		}	
	}
	// (n - 1) - cnt: 추가해야할 간선 수
	// m - cnt는 제거해야할 간선 수 (사이클 때문)
	cout << n - 1 - cnt + (m - cnt);
}
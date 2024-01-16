#include <iostream>

using namespace std;

#define MAX_N 100000

int n, m;
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
	cin >> n >> m;

	// 유니온 파인드를 위한 초기 값 설정
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
	}

	int res;
	int flag = true;

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		int tmp = find(a);
		union_(a, b);
		if (tmp == find(a) and flag) {
			res = i;
			flag = false;
		}
	}

	if (flag) {
		cout << "happy";
	}
	else {
		cout << res;
	}
}
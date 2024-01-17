#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

#define MAX_N 100000

int n, m;
int a, b, w;
int uf[MAX_N + 1];

char arr[MAX_N + 1]; // arr[i]: i번 노드의 종류

tuple<int, int, int> edges[MAX_N + 1]; // 각 간선 정보 저장: (w, a, b)

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

	// 노드 종류 저장
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	// 유니온 파인드를 위한 초기 값 설정
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
	}

	for (int i = 1; i <= m; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		edges[i] = make_tuple(cost, x, y); // cost 순 오름차순 정렬을 위해
	}

	sort(edges + 1, edges + m + 1); // edges의 인덱스 1부터 m까지 정렬

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		// cout << ans << endl;
		int x, y, cost;
		tie(cost, x, y) = edges[i];

		if (find(x) != find(y) && arr[x] != arr[y]) {// 같은 연결 요소가 아니라면
			ans += cost;
			union_(x, y);
		}
	}
	

	bool is_connected = true;
	int root = find(1);
	for (int i = 2; i <= n; i++) {
		if (root != find(i)) {
			is_connected = false;
			break;
		}
	}

	if (is_connected) cout << ans;
	else cout << -1;

	return 0;
}
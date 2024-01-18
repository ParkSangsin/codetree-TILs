#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

#define MAX_N 90000

int n, m; // 가로 줄 간선 개수, 세로 줄 간선 개수
int res;

vector<tuple<int, int, int>> edges;

int uf[MAX_N + 1]; // ux[i]: i번 노드가 가리키는 노드

// x의 루트를 반환하는 함수
int find(int x) {
	if (x == uf[x]) return x;
	uf[x] = find(uf[x]); // 돌아올 때 찾은 루트에 열결
	return uf[x];
}

// x와 y를 연결하는 함수 (x의 루트가 y의 루트를 가리키는 형태)
void union_(int x, int y) {
	x = find(x);
	y = find(y);
	uf[x] = y;
}

int main() {
	cin >> n >> m;

	// i번째줄 j번 노드와 i번째줄 j + 1번 노드 연결
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			int x = (i - 1) * m + j;
			int y = (i - 1) * m + j + 1;
			int w;
			cin >> w;
			edges.push_back({ w, x, y });
		}
	}

	// i번째줄 j번 노드와 i + 1번째줄 j번 노드 연결
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			int x = (i - 1) * m + j;
			int y = i * m + j;
			int w;
			cin >> w;
			edges.push_back({ w, x, y });
		}
	}

	// 오름차순 정렬
	sort(edges.begin(), edges.end());

	// uf 초기 설정
	for (int i = 1; i <= n * m; i++) {
		uf[i] = i;
	}

	for (int i = 0; i < edges.size(); i++) {
		int a, b, w; // a - b 가중치 w
		tie(w, a, b) = edges[i];

		if (find(a) == find(b)) continue;

		union_(a, b);
		res += w;
	}

	cout << res;

	return 0;
}
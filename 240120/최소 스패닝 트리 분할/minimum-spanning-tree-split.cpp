#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_N 200

int n, m; // 가로 줄 간선 개수, 세로 줄 간선 개수
double res;

vector<tuple<double, int, int>> edges;

int uf[MAX_N + 1]; // ux[i]: i번 노드가 가리키는 노드
pair<int, int> coord[MAX_N + 1];

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

	// uf 초기 설정
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
	}

	// 간선 정보 저장
	for (int i = 1; i <= m; i++) {
		int a, b, w;
		cin >> a >> b >> w; // a - b 가중치 w 간선 정보
		edges.push_back({ w, a, b });
	}

	sort(edges.begin(), edges.end());
	int mx_edge = 0;
	int sum = 0;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		tie(w, a, b) = edges[i];

		if (find(a) == find(b)) continue;
		union_(a, b);
		sum += w;
		mx_edge = max(mx_edge, w); // 연결된 간선 중 가장 큰 가중치
	}

	sum -= mx_edge;

	cout << sum;
	return 0;
}
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_N 100000

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

	// 간선 정보 저장
	for (int i = 1; i <= m; i++) {
		int a, b, w;
		cin >> a >> b >> w; // a - b 가중치 w 간선 정보
		edges.push_back({ w, a, b });
	}

	// uf 초기 설정
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
	}

	sort(edges.begin(), edges.end()); // 오름차순
	int max_cnt = 0; // 최소일 경우 빨간 간선 개수
	for (int i = 0; i < m; i++) {
		int a, b, w;
		tie(w, a, b) = edges[i];

		if (find(a) == find(b)) continue;
		union_(a, b);
		if (w == 0) max_cnt ++;
	}

	// uf 설정 초기화
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
	}

	sort(edges.begin(), edges.end(), greater<tuple<int, int, int >>()); // 내림차순 정렬
	int min_cnt = 0;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		tie(w, a, b) = edges[i];

		if (find(a) == find(b)) continue;
		union_(a, b);
		if (w == 0) min_cnt ++;
	}

	int res = (max_cnt * max_cnt) - (min_cnt * min_cnt);
	cout << res;
	return 0;
}
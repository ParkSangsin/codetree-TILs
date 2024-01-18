#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_N 200

int n; // 가로 줄 간선 개수, 세로 줄 간선 개수
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

	// i번노드의 좌표 저장
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		coord[i] = make_pair(x, y);
	}

	// 간선 정보 저장
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b; // a - b 간선 정보
		union_(a, b);
	}

	// 모든 경우의 간선 정보를 edges에 저장
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int x1, y1, x2, y2;
			tie(x1, y1) = coord[i];
			tie(x2, y2) = coord[j];

			double dist = sqrt((long long) (x1 - x2) * (x1 - x2) + (long long) (y1 - y2) * (y1 - y2));
			edges.push_back({ dist, i, j });
		}
	}

	// 오름차순 정렬
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		int a, b;
		double w; // a - b 가중치 w
		tie(w, a, b) = edges[i];

		if (find(a) == find(b)) continue;

		union_(a, b);
		res += w;
	}

	cout << fixed;
	cout.precision(2);
	cout << res;

	return 0;
}
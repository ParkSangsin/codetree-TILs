#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_N 500

int n, m; // 가로 줄 간선 개수, 세로 줄 간선 개수
double res;

int edges[MAX_N + 1][MAX_N + 1]; // edges[i][j]: i번 노드 - j번 노드 최소 가중치
bool visited[MAX_N + 1];
int dist[MAX_N + 1]; // dist[i] : 현재까지 만들어진 MST와 노드 i를 연결하기 위해 필요한 최소 비용

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
	
	// 그래프를 인접 행렬로 표현
	while (m--) {
		int x, y, z;
		cin >> x, y, z;
		
		// 같은 간선이 여러번 등장할 수 있으므로 
		edges[x][y] = (edges[x][y] == 0) ? z : min(edges[x][y], z);
		edges[y][x] = (edges[y][x] == 0) ? z : min(edges[y][x], z);
	}

	// 초기: 무한
	for (int i = 1; i <= n; i++) {
		dist[i] = 100000000;
	}
	dist[1] = 0; // 시작 노드: 1

	int ans = 0;
	for (int i = 1; i <= n; i++) {

		int min_idx = -1; // 아직 방문하지 않은 정점 중 비용이 가장 작은 노드
		for (int j = 1; j <= n; j++) {
			if (visited[j]) continue;

			if (min_idx == -1 || dist[min_idx] > dist[j]) {
				min_idx = j;
			}
		}
		
		// 최솟값에 해당하는 노드에 방문 표시
		visited[min_idx] = true;

		// mst값 갱신
		ans += dist[min_idx];

		// 
		for (int j = 1; j <= n; j++) {
			if (edges[min_idx][j] == 0) continue;
			dist[j] = min(dist[j], edges[min_idx][j]);
		}
	}

	cout << ans;

	return 0;
}
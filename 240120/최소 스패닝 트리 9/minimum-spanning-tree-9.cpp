#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 100000

int n, m; // 가로 줄 간선 개수, 세로 줄 간선 개수
double res;

vector<tuple<int, int>> edges[MAX_N + 1]; // edges[i]: i번 노드에서 갈수 있는 간선
bool visited[MAX_N + 1];
int dist[MAX_N + 1]; // dist[i] : 현재까지 만들어진 MST와 노드 i를 연결하기 위해 필요한 최소 비용
priority_queue<pair<int, int>> pq;

int main() {
	cin >> n >> m;
	
	// 그래프를 인접 행렬로 표현
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;

		edges[x].push_back({ y, z });
		edges[y].push_back({ x, z });
	}

	// 초기: 무한
	for (int i = 1; i <= n; i++) {
		dist[i] = (int)1e9;
	}

	dist[1] = 0; // 시작 노드: 1
	
	pq.push({ 0, 1 }); // { - 가중치, 노드 번호 } (c++은 최대 힙)

	int ans = 0;

	while (!pq.empty()) {
		int min_dist, min_idx; // 가장 가까운 거리, 노드 번호
		tie(min_dist, min_idx) = pq.top();
		pq.pop();

		min_dist = -min_dist;

		if (visited[min_idx]) continue;

		visited[min_idx] = true;
		ans += min_dist;

		// 가장 가까운 노드와 인접한 노드 처리
		for (int i = 0; i < edges[min_idx].size(); i++) {
			int d, idx;
			tie(idx, d) = edges[min_idx][i];

			if (dist[idx] > d) {
				dist[idx] = d;
				pq.push({ -d, idx });
			}
		}
	}
	cout << ans;

	return 0;
}
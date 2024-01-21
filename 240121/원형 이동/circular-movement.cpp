#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 200000

int n, m, k; // 구역 개수, 공사 중 구간 수, 가진 비용

vector<tuple<int, int>> edges[MAX_N + 1];

priority_queue<tuple<int, int>> pq;

int cost[MAX_N + 1]; // dist[i]는 mst에서 i까지 최소 비용
bool visited[MAX_N + 1]; 
bool is_blocked[MAX_N + 1];// i번 노드와 그 옆 노드가 연결되어있는지 확인

int main() {
	cin >> n >> m >> k;

	// 건물 중앙(0번 노드)과 연결
	for (int i = 1; i <= n; i++) {
		int cost;
		cin >> cost;
		edges[0].push_back({ i, cost });
		edges[i].push_back({ 0, cost });
	}

	// 간선의 연결 여부 정보 입력
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y); // x와 y교체 (y가 더 큰 노드번호)

		// x번 노드와 x+1번 노드 사이의 간선이 막혔음을 표시해줍니다.
		if (x == 1 && y == n) is_blocked[n] = true;
		else is_blocked[x] = true;
	}

	// 인접한 막히지 않은 간선들을 연결
	for (int i = 1; i <= n; i++) {
		if (is_blocked[i]) continue;
		
		// x와 y연결
		int x = i;
		int y = i + 1;
		if (x == n)  y = 1;  

		edges[x].push_back({ y, 0 });
		edges[y].push_back({ x, 0 });
	}

	// prim 알고리즘을 위해 dist값 초기화
	for (int i = 0; i <= n; i++) {
		cost[i] = 1e9;
	}
	cost[0] = 0; // 시작 위치는 0

	pq.push({ -0, 0 }); // {-거리, 구역 번호} (C++ 힙은 최대힙이므로)

	int ans = 0;
	while (!pq.empty()) {
		// 가장 가까운 거리에 있는 (비용이 적은) 구역 연결
		int min_cost, min_idx;
		tie(min_cost, min_idx) = pq.top();
		pq.pop();

		min_cost = -min_cost;

		if (visited[min_idx]) continue; // 이미 방문했다면 패스

		visited[min_idx] = true;

		ans += min_cost;

		// min_idx 와 연결된 구역의 최솟값 갱신
		for (int j = 0; j < edges[min_idx].size(); j++) {
			int target_idx, target_cost;
			tie(target_idx, target_cost) = edges[min_idx][j];

			if (cost[target_idx] > target_cost) {
				cost[target_idx] = target_cost;
				pq.push({ -target_cost, target_idx });
			}
		}
	}

	if (ans <= k) cout << 1;
	else cout << 0;

	return 0;
}
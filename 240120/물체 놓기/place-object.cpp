#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 300

int n; // 정점 개수

int cost[MAX_N + 1][MAX_N + 1]; // indir_cost[i][j]: i번 노드에서 j번 노드로 가는 간선의 가중치

int dist[MAX_N + 1]; // dist[i] : 현재 mst에서 i번 노드를 추가할 때 드는 최소 비용
bool visited[MAX_N + 1];

int main() {
	cin >> n;

	// i번 노드에 직접 물체를 놓는 비용
	for (int i = 1; i <= n; i++) {
		cin >> cost[0][i];
	}

	// 간선을 통해 놓는 비용 입력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost[i][j];
		}
	}

	// dist 초기화
	for (int i = 1; i <= n; i++) {
		dist[i] = (int)1e9;
	}
	dist[0] = 0;

	int ans = 0;

	for (int i = 0; i <= n; i++) {
		int min_idx = -1; // 갈 수 있는 노드 중 최소 비용으로 갈 수 있는 노드

		// 갈 수 있는 노드 중 최소 비용으로 갈 수 있는 노드 찾기
		for (int j = 0; j <= n; j++) {
			if (visited[j]) continue; // 방문했으면 건너 뛰기
			if (min_idx == -1 || dist[min_idx] > dist[j]) {
				min_idx = j;
			}
		}
		visited[min_idx] = true;
		ans += dist[min_idx];

		for (int j = 1; j <= n; j++) {
			dist[j] = min(dist[j], cost[min_idx][j]);
		}

	}

	cout << ans;
	return 0;
}
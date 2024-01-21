#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 100000

int n, m; // 도시 개수, 도로 개수

vector<int> edges[MAX_N + 1];
int indegree[MAX_N + 1]; // indegree[i]: i번 노드에 들어오는 간선 수

priority_queue<int> pq;

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		indegree[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			pq.push(-i);
		}
	}

	int cnt = 0;

	while (!pq.empty()) {
		int x = -pq.top();
		pq.pop();
		cout << x << " ";

		for (int i = 0; i < edges[x].size(); i++) {
			int y = edges[x][i];
			indegree[y]--;
			if (indegree[y] == 0) {
				pq.push(-y);
			}
		}
	}

	return 0;
}
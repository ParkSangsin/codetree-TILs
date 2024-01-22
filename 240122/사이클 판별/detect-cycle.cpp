#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 100000

int n, m; // 노드 개수
vector<int> edges[MAX_N + 1];
int indegree[MAX_N + 1]; // indegree[i]: i번 노드에 들어오는 간선 수
bool visited[MAX_N + 1];

queue<int> q;

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
			q.push(i);
		}
	}

	int cnt = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < edges[x].size(); i++) {
			int y = edges[x][i];
			indegree[y]--;
			if (indegree[y] == 0) {
				q.push(y);
			}
		}
	}

	if (cnt == n) cout << "Not Exists";
	else cout << "Exists";

	return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 10000

int n, m; // 노드 개수

vector<int> edges[MAX_N + 1];
int indegree[MAX_N + 1];
queue<int> q;

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		indegree[b]++;
	}

	q.push(1);

	int cnt = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == n) {
			cnt++;
			continue;
		}

		for (int i = 0; i < edges[x].size(); i++) {
			int y = edges[x][i];
			q.push(y);
		}
	}

	cout << cnt;

	return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 1000

int n, m; // 노드 개수

vector<int> edges[MAX_N + 1];
int indegree[MAX_N + 1];
queue<int> q;

int dp[MAX_N + 1]; // 1번 노드에서 i번 노드로 이동 가능한 경우의 수

int res = 1;

bool max_[MAX_N + 1];

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
			dp[i] = 1;
		}
	}


	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < edges[x].size(); i++) {
			int y = edges[x][i];

			if (dp[y] < dp[x]) {
				dp[y] = dp[x];
			}
			else if (dp[y] == dp[x]) {
				dp[y] = dp[x] + 1;
			}

			res = max(res, dp[y]);
			
			indegree[y]--;
			if (indegree[y] == 0) {
				q.push(y);
			}
		}
	}

	cout << res;

	return 0;
}
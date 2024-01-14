#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int n; // 노드의 개수
vector<int> edges[MAX_N + 1];
int par[MAX_N + 1]; // par[i]: i번 노드의 부모 노드
bool visited[MAX_N + 1];

// dp[i][1]: i번 노드에 물건을 두었을 때 최소 개수
// dp[i][0]: i번 노드에 물건을 두지 않았을 때 최소 개수
int dp[MAX_N + 1][2];



void dfs(int x) {
	visited[x] = true;
	// cout << x << endl;
	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];
		if (visited[y]) {
			continue;
		}
		par[y] = x;
		dfs(y);
	}

	dp[x][1] = 1;
	dp[x][0] = 0;

	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];
		if (par[y] == x) {
			dp[x][0] += dp[y][1];
			dp[x][1] += min(dp[y][0], dp[y][1]);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 2; i <= n; i++) {
		int a, b;

		cin >> a >> b;
		
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	dfs(1);

	cout << min(dp[1][0], dp[1][1]);
}
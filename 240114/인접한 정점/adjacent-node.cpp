#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int n, m; 
vector<int> edges[MAX_N + 1];

int dp[MAX_N + 1][2]; // dp[i][1]: i번 노드를 색칠했을 때, 최대값
int arr[MAX_N + 1]; // arr[i]: i번 노드의 값
bool visited[MAX_N + 1];
int par[MAX_N];

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];
		if (visited[y]) {
			continue;
		}
		par[y] = x;
		dfs(y);
	}

	dp[x][0] = 0;
	dp[x][1] = arr[x];

	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];
		if (par[y] == x) {
			dp[x][0] += max(dp[y][0], dp[y][1]);
			dp[x][1] += dp[y][0];
		}
	}

}

int main() {
	cin >> n; // 노드의 수 n

	// 노드 값 저장
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	dfs(1);

	cout << max(dp[1][0], dp[1][1]);
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int n, m; 
vector<int> edges[MAX_N + 1];

int dp[MAX_N + 1]; // dp[i]: i번 노드의 서브트리에 속한 노드 수

void dfs(int x) {
	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];

		dp[y] += dp[x];

		dfs(y);
	}
}

int main() {
	cin >> n >> m; // 노드의 수 n, 초기 연산의 수 m

	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;

		// 루트 노드 무시
		if (p == -1) {
			continue;
		}

		edges[p].push_back(i); // 부모에서 자식으로만 접근 가능
	}

	for (int i = 0; i < m; i++) {
		int x, w;

		cin >> x >> w;
		
		dp[x] += w;
	}

	dfs(1);

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int n, r, q; // 노드의 개수
vector<int> edges[MAX_N + 1];
int par[MAX_N + 1]; // par[i]: i번 노드의 부모 노드
bool visited[MAX_N + 1];

int dp[MAX_N + 1]; // dp[i]: i번 노드의 서브트리에 속한 노드 수
int check[MAX_N + 1]; // 조사할 노드 저장

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

	dp[x] = 1;

	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];
		if (par[y] == x) {
			dp[x] += dp[y];
		}
	}
}

int main() {
	cin >> n >> r >> q; // 트리의 정점 수, 루트 번호,  조사할 정점 수

	for (int i = 0; i < n - 1; i++) {
		int a, b;

		cin >> a >> b;
		
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for (int i = 0; i < q; i++) {
		cin >> check[i];
	}

	dfs(r);

	for (int i = 0; i < q; i++) {
		cout << dp[check[i]] << endl;
	}
}
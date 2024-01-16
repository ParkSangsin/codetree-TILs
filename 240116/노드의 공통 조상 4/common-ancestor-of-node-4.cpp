#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_N 100000
#define MAX_H 17

int n, root;
int a, b; // 공통 조상을 구할 노드
int q; // 질의 횟수
bool visited[MAX_N + 1];
int par[MAX_H + 1][MAX_N + 1]; // par[i][j]: j번 노드에서 부모로 2^i번 이동 했을 때 조상 노드
int depth[MAX_N + 1]; // depth[i]: i번 노드의 깊이
vector<int> edges[MAX_N + 1];

void dfs(int x) {
	visited[x] = true;

	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];
		
		if (visited[y]) continue;

		depth[y] = depth[x] + 1;
		par[0][y] = x;

		dfs(y);
	}
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) {
		return LCA(b, a);
	}

	for (int h = MAX_H; h >= 0; h--) {
		if (depth[a] - depth[b] >= (1 << h)) {
			a = par[h][a];
		}
	}

	if (a == b) return a;

	for (int h = MAX_H; h >= 0; h--) {
		if (par[h][a] != par[h][b]) {
			a = par[h][a];
			b = par[h][b];
		}
	}

	return par[0][a];
}

int main() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int p, c; // 부모 노드, 자식 노드
		cin >> p >> c;
		
		edges[p].push_back(c);
		edges[c].push_back(p);
	}

	depth[1] = 1;
	dfs(1);

	// par 채우기
	for (int h = 1; h <= MAX_H; h++) {
		for (int i = 1; i <= n; i++) {
			par[h][i] = par[h - 1][par[h - 1][i]];
		}
	}

	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << endl;
	}
	return 0;
}
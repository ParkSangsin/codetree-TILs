#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_N 10000

int n, root;
int a, b; // 공통 조상을 구할 노드
bool visited[MAX_N];
int par[MAX_N];
int depth[MAX_N]; // depth[i]: i번 노드의 깊이
vector<int> edges[MAX_N];

void dfs(int x) {
	visited[x] = true;

	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];
		
		if (visited[y]) continue;

		depth[y] = depth[x] + 1;

		dfs(y);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int p, c; // 부모 노드, 자식 노드
		cin >> p >> c;
		
		edges[p].push_back(c);
		edges[c].push_back(p);

		par[c] = p;
	}

	cin >> a >> b;

	// 루트 노드 탐색
	for (int i = 1; i <= n; i++) {
		if (par[i] == 0) {
			root = i;
		}
	}
	// cout << root;

	dfs(root); // dfs를 통해 깊이 저장

	// 깊이를 같게 맞추기
	while (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) {
			a = par[a];
		}
		else {
			b = par[b];
		}
	}

	// 서로 만날 때까지 거슬러 올라가기
	while (a != b) {
		a = par[a];
		b = par[b];
	}

	cout << a;

}
#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>

using namespace std;

#define MAX_N 1000

vector<pair<int, int>> edges[MAX_N + 1];

bool visited[MAX_N + 1]; // visited[i]: i번 노드의 방문 여부 저장

int root; // 루트 노드 번호
int is_tree = 1;

int a, b, c;
int dist = 0;
int dest;
int res;

void dfs(int x) {
	if (x == dest) {
		res = dist;
	}
	visited[x] = true;
	for (int i = 0; i < edges[x].size(); i++) {
		int y, w;
		tie(y, w) = edges[x][i];
		if (visited[y]) {
			continue;
		}
		dist += w;
		dfs(y);
		dist -= w;
	}
}

int main() {
	int n, m; 

	cin >> n >> m;
	
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		memset(visited, false, sizeof(visited));
		dist = 0;
		dest = b;
		dfs(a);
		cout << res << endl;
	}
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100000

vector<int> edges[MAX_N + 1];

bool visited[MAX_N + 1];
int dep[MAX_N + 1];
int ans;

void dfs(int x) {
	visited[x] = true;
	bool is_leaf = true;
	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];
		if (visited[y]) {
			continue;
		}
		is_leaf = false;
		dep[y] = dep[x] + 1;
		dfs(y);
	}
	if (is_leaf) {
		ans += dep[x];
	}
}

int main() {
	int n; 

	cin >> n;
	
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	dfs(1);
	
	if (ans % 2) cout << 1;
	else cout << 0;


	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100000

vector<int> edges[MAX_N + 1];

bool visited[MAX_N + 1];
int par[MAX_N + 1];
vector<int> leafs;

void dfs(int x) {
	visited[x] = true;
	bool is_leaf = true;
	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];
		if (visited[y]) {
			continue;
		}
		is_leaf = false;
		par[y] = x;
		dfs(y);
	}
	if (is_leaf) {
		leafs.push_back(x);
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


	bool turn = true; // true면 a차례, false면 b차례
	int cur;
	for (int i = 0; i < leafs.size(); i++) {
		cur = leafs[i];
		while (true) {
			if (cur == 1) {
				break;
			}
			cur = par[cur];
			turn = !turn;
		}
	}

	if (turn) {
		cout << 0;
	}
	else {
		cout << 1;
	}


	return 0;
}
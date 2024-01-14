#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100000

int n; // 노드의 개수
vector<int> edges[MAX_N + 1];
int arr[MAX_N + 1]; // arr[i]: i번 노드의 값
int par[MAX_N + 1]; // par[i]: i번 노드의 부모 노드
bool visited[MAX_N + 1];
int dp[MAX_N + 1]; // dp[i]: i번 노드와 자식 노드들의 값의 합


void dfs(int x) {
	visited[x] = true;
	// cout << x << endl;
	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];
		if (visited[y]) {
			continue;
		}
		dfs(y);
	}

	dp[x] = arr[x];

	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];
		if (par[y] == x) {
			if (dp[y] >= 0) {
				dp[x] += dp[y];
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 2; i <= n; i++) {
		int t, a, p;

		cin >> t >> a >> p;

		// 조건에 맞게 arr에 노드 값 저장
		if (t == 1) {
			arr[i] = a;
		}
		else {
			arr[i] = -a;
		}
		
		par[i] = p; // i번 노드의 부모 노드는 p번 노드

		edges[i].push_back(p);
		edges[p].push_back(i);
	}

	dfs(1);

	cout << dp[1];

	/*for (int i = 1; i <= n; i++) {
		cout << dp[i] << endl;
	}*/
}
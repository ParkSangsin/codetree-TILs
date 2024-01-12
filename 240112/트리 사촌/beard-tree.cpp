#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100000

int a[MAX_N + 1];
int par[MAX_N + 1];

int ans; // 사촌 노드의 개수
int n, k;

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int par_node = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] > a[i - 1] + 1) {
			par_node++;
		}
		par[i] = par_node;
	}

	for (int i = 1; i <= n; i++) {
		if (!par[par[i]] || !par[par[k]]) continue;

		if (par[i] != par[k] && par[par[i]] == par[par[k]]) ans++;
	}

	cout << ans;	
	return 0;
}
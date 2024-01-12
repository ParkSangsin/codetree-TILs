#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100000

int a[MAX_N + 1]; // a[i]: i번째 입력 받은 노드 값
int par[MAX_N + 1]; // par[i]: i번 노드의 부모 노드 번호 (입력 순서)

int ans; // 사촌 노드의 개수
int n, k;
int finding_node; // 사촌을 구해야하는 노드의 번호 (입력 순서)

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k)
			finding_node = i;
	}

	int par_node = 0; // 부모 노드 번호 (입력 순서)
	for (int i = 2; i <= n; i++) {
		if (a[i] > a[i - 1] + 1) { // 다음에 입력 받은 노드 값이 연속되지 않은 경우
			par_node++;
		}
		par[i] = par_node;
	}

	for (int i = 1; i <= n; i++) {
		// 부모의 부모 노드가 존재하지 않는 경우 (루트의 부모 노드: 0)
		if (!par[par[i]] || !par[par[finding_node]]) continue;

		// 부모 노드는 다르면서, 부모의 부모 노드는 같은 경우
		if (par[i] != par[finding_node] && par[par[i]] == par[par[finding_node]]) ans++;
	}

	cout << ans;	
	return 0;
}
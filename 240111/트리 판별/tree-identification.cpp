#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define MAX_N 10000

vector<int> edges[MAX_N];

bool visited[MAX_N + 1]; // visited[i]: i번 노드의 방문 여부 저장
bool used[MAX_N + 1]; // used[i]: i번 노드의 존재 유무 저장
int deg[MAX_N + 1]; // deg[i]: i번 노드로 들어오는 간선의 개수 저장

int root; // 루트 노드 번호
int is_tree = 1;

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];
		if (visited[y]) {
			continue;
		}
		dfs(y);
	}
}

int main() {
	int m; // 간선의 개수

	cin >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);

		// 그래프에 있는 정점 번호 저장
		used[a] = used[b] = true;

		deg[b]++;
	}

	// 존재하는 노드 중 들어오는 간선이 하나도 없는 노드가 여러 개라면, 트리가 아니다.
	// 하나만 있다면, 그것이 루트 노드이다.
	for (int i = 1; i <= MAX_N; i++) {
		if (used[i] && deg[i] == 0) {
			if (root != 0) { // root의 초기 값이 0이므로 0이 아니라면, 이미 루트노드가 정해진 상황이다. -> 루트 노드가 2개인 상황
				is_tree = 0;
			}
			root = i;
		}
	}

	if (root == 0) {
		is_tree = 0;
	}

	// 루트 노드를 제외한 모든 노드는 단 하나의 들어오는 간선만 존재
	for (int i = 1; i <= MAX_N; i++) {
		if (used[i] && deg[i] != 1 && root != i) {
			is_tree = 0;
			break;
		}
	}

	dfs(root);

	// 사용한 모든 노드에 방문되어야 함
	for (int i = 1; i <= MAX_N; i++) {
		if (used[i] && !visited[i]) {
			is_tree = 0;
			break;
		}
	}

	cout << is_tree;
	return 0;
}
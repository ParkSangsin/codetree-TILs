#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define MAX_N 50

// 크기가 MAX_N + 1인 배열 생성 (초기 = 쓰레기값)
bool is_deleted[MAX_N]; // 노드들의 삭제 여부를 저장하는 배열
int parents[MAX_N]; // 부모 노드 번호 저장

// edge들의 정보를 저장하는 vector 생성
vector<int> edges[MAX_N]; // 자식 노드들을 저장

int cnt; // 리프노드 개수
int root; // 루트 노드 번호

void dfs(int x) {
	// 삭제된 노드 건너뛰기
	if (is_deleted[x]) {
		return;
	}

	bool is_leaf = true;

	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];

        // 자식 노드가 삭제된 경우
		if (is_deleted[y]) {
			continue;
		}
		dfs(y);
		is_leaf = false; // 자식 노드가 있다면, 리프노드가 아님
	}

	if (is_leaf) {
		cnt++;
	}
}
 
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> parents[i];

		x = i;
		y = parents[i];

		// 루트 노드 찾기
		if (y == -1) {
			root = x;
			continue;
		}

		edges[y].push_back(x);
	}

	int r; // 지울 노드 번호
	cin >> r;
	
	is_deleted[r] = true;

	dfs(root);

	cout << cnt;

	return 0;
}
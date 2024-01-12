#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define MAX_N 100000

// 크기가 MAX_N + 1인 배열 생성 (초기 = 쓰레기값)
vector<int> visited(MAX_N + 1); // 방문 여부 저장 
int parents[MAX_N + 1]; // 부모 노드 번호 저장

// edge들의 정보를 저장하는 vector 생성
vector<pair<int, int>> edges[MAX_N + 1]; // 각 요소는 vector 배열을 갖는다.

int mx;
int mx_node;

void dfs(int x, int total) {
	visited[x] = 1;

	if (mx < total) {
		mx = total;
		mx_node = x;
	}

	for (int i = 0; i < edges[x].size(); i++) {
		int y, d;
		tie(y, d) = edges[x][i]; // tie함수를 이용한 튜플 언패킹

		if (visited[y]) {
			continue;
		}
		dfs(y, total + d);
	}
}
 
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b, d;
		cin >> a >> b >> d;

		edges[a].push_back(make_pair(b, d));  // 벡터의 a번째 요소에 벡터를 스스로 생성하여 b 삽입
		edges[b].push_back(make_pair(a, d));
	}

	mx = -1;
	mx_node = -1;

	dfs(1, 0);

	int x = mx_node;
	mx = -1;
	mx_node = -1;

	visited.assign(MAX_N + 1, 0);

	dfs(x, 0);
	
	cout << mx;

	return 0;
}
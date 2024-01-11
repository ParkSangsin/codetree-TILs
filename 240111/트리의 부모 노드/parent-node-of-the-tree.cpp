#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100000

// 크기가 MAX_N + 1인 배열 생성 (초기 = 쓰레기값)
bool visited[MAX_N + 1]; // 방문 여부 저장 
int parents[MAX_N + 1]; // 부모 노드 번호 저장

// edge들의 정보를 저장하는 vector 생성
vector<int> edges[MAX_N + 1];

void dfs(int x) {
	visited[x] = 1;
	for (int i = 0; i < edges[x].size(); i++) {
		int y = edges[x][i];
		if (visited[y]) {
			continue;
		}
		parents[y] = x;
		dfs(y);
	}
}
 
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);  // 벡터의 a번째 요소에 벡터를 스스로 생성하여 b 삽입
		edges[b].push_back(a);
	}

	visited[1] = 1;
	dfs(1);

	for (int i = 2; i < n + 1; i++) {
		cout << parents[i] << endl;
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 1000

int n, m; // 노드 개수
map<string, int> str_nodes;
string nodes[MAX_N + 1]; // 입력 받은 문자열 저장
vector<int> edges[MAX_N + 1];
int indegree[MAX_N + 1]; // indegree[i]: i번 노드에 들어오는 간선 수
vector<int> root; // 루트에 해당하는 노드번호 저장
vector<int> child[MAX_N + 1]; // i번 노드의 자식들 저장

queue<int> q;

int main() {
	cin >> n;

	// 입력 받은 순서로 노드 이름 저장 (문자열)
	for (int i = 1; i <= n; i++) {
		cin >> nodes[i];
	}

	// 노드 이름을 사전순으로 정렬
	sort(nodes + 1, nodes + n + 1); 

	// 노드 이름과 대응하는 노드 번호를 str_nodes에 저장
	for (int i = 1; i <= n; i++) {
		str_nodes[nodes[i]] = i;
	}

	cin >> m;
	
	for (int i = 0; i < m; i++) {
		string a_str, b_str;
		cin >> a_str >> b_str;
		
		// 문자에 대응하는 노드번호로 변경 후 인접리스트에 저장
		int a, b;
		a = str_nodes[a_str];
		b = str_nodes[b_str];

		edges[b].push_back(a);
		indegree[a]++;
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			root.push_back(i);
			q.push(i);
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < edges[x].size(); i++) {
			int y = edges[x][i];
			indegree[y]--;
			if (indegree[y] == 0) {
				q.push(y);
				child[x].push_back(y);
			}
		}
	}

	// 자식 노드를 이름 순 정렬
	for (int i = 1; i <= n; i++)
		sort(child[i].begin(), child[i].end());

	cout << root.size() << "\n";
	for (int i = 0; i < root.size(); i++) {
		cout << nodes[root[i]] << " ";
	}
	cout << "\n";

	for (int i = 1; i <= n; i++) {
		cout << nodes[i] << " ";
		cout << child[i].size() << " ";
		for (int j = 0; j < child[i].size(); j++) {
			cout << nodes[child[i][j]] << " ";
		}
		cout << "\n";
	}
	return 0;
}
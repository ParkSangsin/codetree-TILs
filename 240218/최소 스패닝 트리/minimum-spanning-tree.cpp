#include <iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<queue>

#define MAX_N 100000

using namespace std;

vector<tuple<int, int, int>> v;

int uf[MAX_N + 1];
int n, m;

int find(int x) {
	if (uf[x] == x) return x;
	uf[x] = find(uf[x]);
	return uf[x];
}

void union_(int x, int y) {
	x = find(x);
	y = find(y);

	uf[x] = y;
}

int main() {
   
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		uf[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;

		v.push_back({ w, a, b });
	}

	int res = 0;

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int w, a, b;
		tie(w, a, b) = v[i];

		if (find(a) == find(b)) continue;

		union_(a, b);
		res += w;
	}

	cout << res;

}
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define MAX_N 1010

int n;

// (그림 참고)
long long dp[MAX_N][MAX_N]; // 시작점에서 서로 겹치지 않게 순서대로 선택하면서 한 점은 i, 한 점은 j에 있는 상황 일때, 거리 최솟값
vector<pair<int, int>> points;

// i번 점과 j번 점 사이의 거리 계산
int dist(int i, int j) {
	int x1, y1;
	int x2, y2;
	tie(x1, y1) = points[i];
	tie(x2, y2) = points[j];

	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points.push_back({ x, y });
	}

	// x좌표 순 오름차순 정렬
	sort(points.begin(), points.end());

	// dp 초기값 설정
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = (long long)1e16;
		}
	}

	// 출발은 0번점에서 시작
	dp[0][0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int next = max(i, j) + 1;

			if (next == n)
				continue;

			dp[next][j] = min(dp[next][j], dp[i][j] + dist(i, next));
			dp[i][next] = min(dp[i][next], dp[i][j] + dist(j, next));
		}
	}

	long long ans = (long long)1e16;
	for (int i = 0; i < n - 1; i++)
		ans = min(ans, dp[i][n - 1] + dist(i, n - 1));

	cout << ans;

	return 0;
}
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define MAX_N 2000

int n;
int ans;

int dp[MAX_N][MAX_N]; // dp[i][j]: [i, j] 구간에 있는 문자열에서 좌우 대칭을 위해 제거해야하는 최소 문자 수

string str;

// [i, j] 구간에 좌우 대칭을 위해 필요한 제거 문자 수
int minStr(int i, int j) {
	// 이미 이전에 구한 경우
	if (dp[i][j] != 1e9) {
		return dp[i][j];
	}

	if (i >= j) {
		dp[i][j] = 0;
		return 0;
	}

	dp[i][j] = min(dp[i][j], minStr(i, j - 1) + 1);
	dp[i][j] = min(dp[i][j], minStr(i + 1, j) + 1);

	if (str[i] == str[j]) {
		dp[i][j] = min(dp[i][j], minStr(i + 1, j - 1));
	}
	return dp[i][j];
}

int main() {
	cin >> str;
	n = str.length();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 1e9;
		}
	}

	cout << minStr(0, n - 1);

	return 0;
}
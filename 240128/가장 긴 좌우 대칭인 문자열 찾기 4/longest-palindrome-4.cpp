#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define MAX_N 550

int n;
int ans = 1;

bool dp[MAX_N][MAX_N]; // dp[i][j]: [i, j] 구간에 있는 문자열이 좌우 대칭인 문자열이면 true

string str;

int main() {
	cin >> str;
	n = str.length();

	// dp 초기값 설정 (구간의 길이가 1인 경우)
	for (int i = 0; i < n; i++)
		dp[i][i] = true;

	// dp 초기값 설정 (구간의 길이가 2인 경우)
	for (int i = 0; i < n - 1; i++) {
		if (str[i] == str[i + 1]) {
			dp[i][i + 1] = true;
			ans = 2; // ans 갱신
		}
	}

	for (int gap = 3; gap <= n; gap++) { // 구갖 길이 지정
		for (int i = 0; i <= n - gap; i++) { // 시작 위치 지정
			int j = i + gap - 1; // 끝 위치 지정
			if (dp[i + 1][j - 1] && str[i] == str[j]) {
				dp[i][j] = true;
				ans = gap;
			}
		}
	}

	cout << ans;

	return 0;
}
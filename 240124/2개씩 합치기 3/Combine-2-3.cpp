#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define MAX_N 550

int n;

int dp[MAX_N][MAX_N];

int arr[MAX_N];

int prefix[MAX_N]; // prefix[i]: 0 ~ i 구간에 있는 수들의 합

// i ~ j 구간에 있는 수들의 합
int getSum(int i, int j) {
	return prefix[j] - prefix[i] + arr[i];
}

int findMin(int i, int j) {
	// 이미 이전에 구했을 경우
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (i == j) {
		dp[i][j] = 0;
		return 0;
	}

	int min_cost = (int)1e9; // 구간을 나누었을 때 나올 수 있는 최솟값 (초기: 최댓값)

	for (int k = i; k < j; k++) {
		int cost = findMin(i, k) + findMin(k + 1, j) + getSum(i, j);
		min_cost = min(min_cost, cost);
	}

	return dp[i][j] = min_cost;

}

int main() {
	cin >> n;
	// 입력
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// dp 초기값 설정
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = -1;

	// 누적합 계산
	prefix[0] = arr[0];
	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}

	cout << findMin(0, n - 1);

	return 0;
}
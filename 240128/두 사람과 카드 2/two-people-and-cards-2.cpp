#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

#define MAX_N 2000

using namespace std;

// 변수 선언
int n, m;
int A[MAX_N + 1][2]; // 수열 A 저장
int dp[MAX_N + 1][MAX_N + 1]; // dp[i][j]: 한 사람이 i, 한 사람이 j번째까지 카드를 선택할 때, 최소 점수 합 

int Dist(int x, int y) {
    if (x == 0) return 0; // 주의!!
    return abs(A[x][0] - A[y][0]);
}

int main() {
    // 수열 A 입력
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i][0];
    }

    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        A[x][1] = 1;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 1e9;
        }
    }

    dp[0][0] = 0; // 아무도 선택하지 않을 경우에서 출발

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int next = max(i, j) + 1;

            if (next == n + 1) continue;

            // 첫번째 사람이 next를 선택할 경우
            dp[next][j] = min(dp[next][j], dp[i][j] + Dist(i, next));

            // 두번째 사람이 next를 선택할 경우
            if (A[next][1] == 0) dp[i][next] = min(dp[i][next], dp[i][j] + Dist(j, next));
        }
    }

    int res = 1e9;
    for (int i = 0; i < n; i++) {
        res = min(dp[n][i], res);
        res = min(dp[i][n], res);
    }

    cout << res;

    return 0;
}
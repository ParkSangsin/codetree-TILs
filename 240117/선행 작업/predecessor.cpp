#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int n;
bool visited[MAX_N + 1];
vector<int> edges[MAX_N + 1]; // edges[i]: i번 노드로 들어오는 노드 번호 저장 
queue<int> q;

int indegree[MAX_N + 1]; // indegree[i]: i번일을 하기 위해 필요한 진입 차수
int arr[MAX_N + 1]; // 각 일을 완료하는데 걸리는 시간
int dp[MAX_N + 1]; // dp[i]: i번 일을 완료하기 위해 필요한 최소 시간

int main() {
    cin >> n;

    // i번 노드의 정보 입력
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> arr[i] >> num;
        while (num--) {
            int x;
            cin >> x;
            edges[x].push_back(i); 
            indegree[i]++; // i번 노드의 진입차수 증가
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) { // 진입차수가 0인 노드를 먼저 큐에 저장
            q.push(i);

            // 초기 dp값 설정
            dp[i] = arr[i];
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < edges[x].size(); i++) {
            int y = edges[x][i];

            dp[y] = max(dp[y], dp[x] + arr[y]);
            indegree[y]--;

            if (!indegree[y]) q.push(y);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);

    cout << ans;
    return 0;
}
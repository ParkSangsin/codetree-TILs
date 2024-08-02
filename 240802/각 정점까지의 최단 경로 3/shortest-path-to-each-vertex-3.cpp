#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

# define ll long long
# define INF 1e9

using namespace std;

int n, m;

vector<tuple<int, int>> edges[110];

priority_queue<tuple<int, int>> pq;

int dist[110];

int main() {
    // 입출력 단축 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, w;

        cin >> a >> b >> w;

        edges[a].push_back({ b, w });
    }

    for (int i = 1; i <= n; i++) {
         dist[i] = INF;
    }

    dist[1] = 0;

    pq.push({ 0, 1 });
    
    while (!pq.empty()) {
        int w, x;
        tie(w, x) = pq.top();
        w = -w;
        pq.pop();

        for (int i = 0; i < edges[x].size(); i++) {
            int nx, nw;
            tie(nx, nw) = edges[x][i];

            if (dist[nx] > dist[x] + nw) {
                dist[nx] = dist[x] + nw;
                pq.push({ dist[nx], nx });
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
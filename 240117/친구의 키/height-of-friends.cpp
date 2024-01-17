#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define MAX_N 100000

int n, m;
bool visited[MAX_N + 1];
vector<int> edges[MAX_N + 1];
stack<int> st;

void dfs(int x) {
    visited[x] = true;
    for (int i = 0; i < edges[x].size(); i++) {
        int y = edges[x][i];
        if (visited[y]) continue;
        dfs(y);
    }
    st.push(x);
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }

	for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i);
        }
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
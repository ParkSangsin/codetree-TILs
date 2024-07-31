#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int n, m;

unordered_map<string, int> um;

int main() {

    cin >> n;

    int res = 0;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if (um.find(str) == um.end()) {
            um[str] = 1;
        }
        else {
            um[str]++;
        }

        res = max(res, um[str]);
    }

    cout << res;

    return 0;
}
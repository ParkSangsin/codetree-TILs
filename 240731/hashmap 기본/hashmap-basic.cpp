#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, res;

unordered_map<int, int> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if (str == "add") {
            int k, v;
            cin >> k >> v;
            m[k] = v;
        }
        else if (str == "find") {
            int k;
            cin >> k;

            if (m.find(k) == m.end()) {
                cout << "None\n";
            }
            else {
                cout << m[k] << "\n";
            }
        }
        else if (str == "remove") {
            int k;
            cin >> k;
            m.erase(k);
        }
    }


    return 0;
}
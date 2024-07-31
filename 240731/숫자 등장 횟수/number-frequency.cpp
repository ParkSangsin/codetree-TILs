#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int n, m;

unordered_map<int, int> hash_map;

vector<int> res;

int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        
        if (hash_map.find(num) == hash_map.end()) {
            hash_map[num] = 1;
        }
        else {
            hash_map[num]++;
        }
    }

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        
        if (hash_map.find(num) == hash_map.end()) {
            cout << 0 << " ";
        }
        else {
            cout << hash_map[num] << " ";
        }
    }

    return 0;
}
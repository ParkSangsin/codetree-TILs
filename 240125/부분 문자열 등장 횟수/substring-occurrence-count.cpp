#include <iostream>
#include <string>
#include <vector>

#define MAX_M 100010

using namespace std;

// 변수 선언
int n, m;
string text, pattern;

// f[i] : pattern에서 [1, i]로 이루어진 문자열 중 접두사와 접미사가 일치하는 최장 길이 (단, 자기자신은 제외)
int f[MAX_M + 1];


int main() {
    cin >> text >> pattern;

    n = text.size();
    m = pattern.size();

    text = "#" + text;
    pattern = "#" + pattern;

    f[0] = -1;
    for (int i = 1; i <= m; i++) {
        int j = f[i - 1];

        while (j >= 0 && pattern[j + 1] != pattern[i]) {
            j = f[j];
        }

        f[i] = j + 1;
    }

    int j = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        while (j >= 0 && pattern[j + 1] != text[i]) {
            j = f[j];
        }
        j++;

        if (j == m) {
            j = f[j];
            ans++;
        }
    }

    cout << ans;
    return 0;
}
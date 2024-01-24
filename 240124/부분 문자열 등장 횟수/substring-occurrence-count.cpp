#include <iostream>
#include <string>

#define MAX_M 100000

using namespace std;

// 변수 선언
int n, m;
int q;
string text, pattern;

// f[i] : pattern에서 [1, i]로 이루어진 문자열 중 접두사와 접미사가 일치하는 최장 길이 (단, 자기자신은 제외)
int f[MAX_M + 1];

int main() {

    cin >> text >> q;

    // 1번 인덱스부터 시작하기 위해 "#" 추가
    text = "#" + text;
    pattern = "#" + pattern;

    while (q--) {
        cin >> pattern;

        n = text.size();
        m = pattern.size();

        // 실패함수 계산
        f[0] = -1; 
        for (int i = 1; i <= m; i++) {
            int j = f[i - 1]; // 이전 실패함수부터 시작

            // 접두사와 접미사가 일치하는 인덱스 찾기
            while (j >= 0 && pattern[j + 1] != pattern[i])
                j = f[j];
            f[i] = j + 1; // j가 0이 되면 f[j]가 -1이 되기 때문에 +1
        }
        
        int ans = 0;
        int j = 0;

        // 한 문자씩 비교하여 패턴과 일치하는 순간 탐색
        for (int i = 1; i <= n; i++) {
            // 패턴과 일치하는 가장 긴 길이
            while (j >= 0 && pattern[j + 1] != text[i])
                j = f[j];

            // 이 순간, j는 일치하는 인덱스
            j++; // 그 다음 인덱스로 

            // j가 m이 되면 모두 일치
            if (j == m) {
                ans++;
                j = f[j];
            }
        }

        cout << ans << endl;
    }
    return 0;
}
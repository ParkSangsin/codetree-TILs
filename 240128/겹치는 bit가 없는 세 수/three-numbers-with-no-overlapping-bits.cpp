#include <iostream>

#define MAX_N 500

using namespace std;

// 변수 선언
int n;
int arr[MAX_N];

int main() {
    // 입력:
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // 모든 숫자에 대해 겹치지 않는 쌍을 찾습니다.
    // 맞을 경우 합을 더해줍니다.
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++) {
                // 숫자들의 비트가 겹치지 않는다면
                // 세 숫자의 합과, 세 숫자의 or연산의 값이 같습니다.
                if(arr[i] + arr[j] + arr[k] == (arr[i] | arr[j] | arr[k])) {
                    ans = max(ans, arr[i] + arr[j] + arr[k]);
                }
            }

    // 조건을 만족하는 경우 중 얻을 수 있는 최대 합을 출력합니다.
    cout << ans;

    return 0;
}
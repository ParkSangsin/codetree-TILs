#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 1000020

string temp, str;
int n; // str의 크기

int A[MAX_N];// A[i]: i인덱스를 중심으로 하는 펠린드롬 중 가장 긴 펠린드롬의 길이

int main() {
	cin >> temp;

	// # 넣어서 홀수로 만들기
	for (int i = 0; i < temp.size(); i++) {
		str += "#";
		str += temp[i];
	}
	str += "#";

	n = str.size();

	int r = -1, p = -1; // r은 확인된 펠린드롬 범위, p는 r을 만들 수 있는 중심

	for (int i = 0; i < n; i++) {
		// A 설정 단축
		if (r >= i) {
			int ii = p - (i - p); // p를 기준으로 대칭된 좌표
			A[i] = min(r - i, A[ii]); // r - i 보다 긴 펠린드롬은 장담할 수 없음
		}

		// i를 중심으로 최대로 뻗기
		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < n && // 문자열 길이를 벗어나지 않고,
			str[i - A[i] - 1] == str[i + A[i] + 1]) { // 비교할 양쪽 끝 값이 같다면
			A[i]++;
		}

		// p, r 값을 갱신
		if (i + A[i] > r) {
			r = i + A[i];
			p = i;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, 2 * A[i] + 1);

	// 처음 주어진 문자열에서 
	// #을 제외한 부분의 길이가 실제 답이 되기에
	// 2로 나눴을 때의 몫이 답이 됩니다.
	cout << ans / 2;

	return 0;
}
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 200020

string temp, str;
int n, q; // str의 크기

int A[MAX_N];// A[i]: i인덱스를 중심으로 하는 펠린드롬 중 가장 긴 펠린드롬의 길이
vector<int> B;
int cnt;

int main() {
	cin >> n >> q;
	cin >> temp;

	// 문자 사이에 #을 붙여 홀수 만들기
	for (int i = 0; i < n; i++) {
		str += "#";
		str += temp[i];
	}
	str += "#";

	n = str.size();

	int r = -1, p = -1;

	for (int i = 0; i < n; i++) {
		if (r >= i) {
			int ii = p - (i - p);
			A[i] = min(r - i, A[ii]);
		}

		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < n &&
			str[i - A[i] - 1] == str[i + A[i] + 1]) {
			A[i]++;
		}

		if (r < i + A[i]) {
			r = i + A[i];
			p = i;
		}
	}

	for (int i = 0; i < q; i++) {
		int a, b, idx;
		cin >> a >> b; // 실제 문자열 temp의 인덱스

		// 위에서 변환한 문자열 str의 인덱스
		a = 2 * a - 1; 
		b = 2 * b - 1;
		
		idx = (a + b) / 2; // 중앙 인덱스

		int max_len = 2 * A[idx] + 1; // idx를 중앙으로하는 최장 펠린드롬 길이

		if (max_len >= b - a + 1) cout << "Yes" << "\n";
		else cout << "No" << "\n";
	}

	return 0;
}
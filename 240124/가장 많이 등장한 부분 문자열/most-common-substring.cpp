#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define MAX_N 100000

int n, l;
string text;

int p[2] = { 31, 37 };
int m[2] = { int(1e9) + 7, int(1e9) + 9 };

// p_pow[k][i]: p^i 을 m으로 나눈 나머지
long long p_pow[2][MAX_N + 1];  

// {i, j}, a: i~j 부분 문자열이 a번 등장함을 저장 
map<pair<int, int>, int> freq;

int ans;

int ToInt(char c) {
	return c - 'a' + 1;
}

int main() {
	cin >> l >> text; // 부분 문자열 길이, text 입력

	n = text.size(); // text 길이

	// 2번 해싱
	for (int k = 0; k < 2; k++) {
		p_pow[k][0] = 1; // 초기 1
		for (int i = 1; i <= n; i++) {
			p_pow[k][i] = (p_pow[k][i - 1] * p[k]) % m[k];
		}
	}

	// text에서 구간 [0, l - 1]에 해당하는 해싱값을 계산
	long long t_h[2] = { 0 };
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < l; i++) {
			t_h[k] = (t_h[k] + ToInt(text[i]) * p_pow[k][l - 1 - i]) % m[k];
		}
	}

	freq[{t_h[0], t_h[1]}]++;
	ans = max(ans, freq[make_pair(t_h[0], t_h[1])]);

	for (int i = 1; i <= n - l; i++) {
		for (int k = 0; k < 2; k++) {
			t_h[k] = t_h[k] * p[k] - ToInt(text[i - 1]) * p_pow[k][l] + ToInt(text[i + l - 1]) % m[k];
			if (t_h[k] < 0)
				t_h[k] += m[k];
		}
		// 해싱된 값을 map에 저장합니다.
		freq[make_pair(t_h[0], t_h[1])]++;
		ans = max(ans, freq[make_pair(t_h[0], t_h[1])]);
	}

	cout << ans;

	return 0;
}
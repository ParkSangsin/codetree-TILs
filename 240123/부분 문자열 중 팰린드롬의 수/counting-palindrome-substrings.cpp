#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 200020

string temp, str;
int n; // str의 크기

int A[MAX_N];// A[i]: i인덱스를 중심으로 하는 펠린드롬 중 가장 긴 펠린드롬의 길이

int cnt;

int main() {
	cin >> temp;

	// 문자 사이에 #을 붙여 홀수 만들기
	for (int i = 0; i < temp.size(); i++) {
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

	for (int i = 0; i < n; i++) {

		
		cnt += (A[i] + 1) / 2; // 만들 수 있는 펠린드롬 개수
	}

	cout << cnt;

	return 0;
}
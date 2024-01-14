#include <iostream>
using namespace std;

#define MAX_N 1024
int n, k;
int a[MAX_N + 1]; // 중위 순회한 순서대로 노드 번호 저장
int tree_num[MAX_N + 1]; // 이진 트리 순서대로 노드 번호 저장
int cnt = 1; // 현재 처리 중인 중위 순회 순서 노드 번호

// tree_num (빈 트리)를 중위 순회하며 
void inorder(int x) { // x는 이진 트리 순서 번호 (루트: 1)
	if (x > n) {
		return;
	}
	inorder(x * 2); // 왼쪽 자식 중위 순회
	tree_num[x] = a[cnt++];
	cout << tree_num[x] << endl;
	inorder(x * 2 + 1); // 오른쪽 자식 중위 순회

}

int main() {
	cin >> k; // 트리의 깊이

	n = (1 << k) - 1; // n = 2^k - 1 (노드 개수)

	// 중위 순회 순서 입력
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	// 1번 노드부터 중위 순회
	inorder(1);

	// 트리 구조에 맞게 출력
	for (int i = 1; i <= k; i++) {
		// 깊이가 i일 때, 노드의 개수는 2^(i-1)
		for (int j = (1 << (i - 1)); j <= (1 << i) - 1; j++) {
			cout << tree_num[j] << " ";
		}
		cout << endl;
	}
}
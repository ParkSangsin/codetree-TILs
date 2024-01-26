#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

#define MAX_N 10000

using namespace std;

// 변수 선언
int n;
string words[MAX_N];

// Trie 노드 정의
class TrieNode {
    public:
        // 노드의 자식 노드를 가리키는 포인터를 저장하는 배열
        TrieNode* children[10]; // children[i]: 'i' 노드를 가리키는 포인터
        bool is_end; // 해당 노드 기점으로 하나의 단어가 완성되는지 체크
        
        // 생성자
        TrieNode() {
            is_end = false; // 초기값: 단어 완성 x
            
            // 각 문자에 대응되는 노드 정보는 일단 nullptr
            for (int i = 0; i < 10; i++) {
                children[i] = nullptr; // 널포인터로 세팅
            }
        }
};

TrieNode* root = new TrieNode(); // 루트 노드 생성

// Trie에 문자열 저장하는 함수
void InsertWord(string s) {
    TrieNode* cur = root;
    for (int i = 0; i < s.size(); i++) {
        int idx = s[i] - '0'; // 자식 노드에 저장할 위치

        // cur의 자식 노드에 s[i]가 저장되어 있지 않다면
        if (cur->children[idx] == nullptr) {
            cur->children[idx] = new TrieNode(); // 자식 노드에 s[i] 추가
        }

        // 자식 노드로 이동
        cur = cur->children[idx]; 
    }
    cur->is_end = true; // 마지막 위치 노드 is_end 변경
}

bool searchWord(string s) {
    TrieNode* cur = root; // root에서 탐색 시작
    for (int i = 0; i < s.size(); i++) {
        // 도중에 끝난 글자가 있으면 접두사 발견
        if (cur->is_end) {
            return true;
        }

        // 다음 글자로 이동
        int idx = s[i] - '0';
        cur = cur->children[idx];
    }
    return false;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> words[i]; // word 저장
    }

    // Trie에 word 저장
    for (int i = 0; i < n; i++) {
        InsertWord(words[i]);
    }

    bool exists = false; // 탐색 중에 끝이라고 표시된 노드가 존재하는지 확인
    for (int i = 0; i < n; i++) {
        if (searchWord(words[i])) { // 한 단어를 탐색 중에 end를 거치면 접두사 발견
            exists = true;
        }
    }
    
    if (exists) {
        cout << 0;
    }
    else {
        cout << 1;
    }

    return 0;
}
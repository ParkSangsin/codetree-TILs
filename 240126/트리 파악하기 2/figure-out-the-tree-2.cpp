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

class TrieNode {
    public:
        TrieNode* children[26];
        bool is_end;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            is_end = false;
        }
};

TrieNode* root = new TrieNode();

void insertWord(string s) {
    TrieNode* cur = root;
    for (int i = 0; i < s.size(); i++) {
        int idx = s[i] - 'A';
        if (cur->children[idx] == nullptr) {
            cur->children[idx] = new TrieNode();
        }
        cur = cur->children[idx];
    }
    cur->is_end = true;
}

void printTrie(TrieNode* Node, int depth) {
    for (int idx = 0; idx < 26; idx++) {
        if (Node->children[idx] == nullptr) continue;
        for (int i = 0; i < depth; i++) {
            cout << "--";
        }
        cout << (char)('A' + idx) << "\n";
        printTrie(Node->children[idx], depth + 1);
    }
}


int main() {
    cin >> n;

    // 문자열 입력
    for (int i = 0; i < n; i++) {
        int len;
        string str;
        cin >> len;
        for (int j = 0; j < len; j++) {
            string ch;
            cin >> ch;
            str += ch;
        }
        words[i] = str;
    }

    // Trie에 문자열 입력
    for (int i = 0; i < n; i++) {
        insertWord(words[i]);
    }

    printTrie(root, 0);
    return 0;
}
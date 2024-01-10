def preorder(root): # 전위 순회
    if root != '.':
        print(root, end = '') # root 노드 출력
        preorder(tree[root][0]) # left 자식 노드를 root로 탐색
        preorder(tree[root][1]) # right 자식 노드를 root로 탐색

def inorder(root): # 중위 순회
    if root != '.':
        inorder(tree[root][0]) # left 자식 노드를 root로 탐색
        print(root, end = '') # root 노드 출력
        inorder(tree[root][1]) # right 자식 노드를 root로 탐색

def postorder(root): # 후위 순회
    if root != '.':
        postorder(tree[root][0]) # left 자식 노드를 root로 탐색
        postorder(tree[root][1]) # right 자식 노드를 root로 탐색
        print(root, end = '') # root 노드 출력

N = int(input()) # 입력 받을 이진 노드의 개수

tree = {} 
# 트리 딕셔너리
# key: 루트 노드, value: key의 자식 노드들 [좌, 우]

for n in range(N):
    root, left, right = input().split()
    tree[root] = [left, right]

preorder('A')
print()
inorder('A')
print()
postorder('A')
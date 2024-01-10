import sys
sys.setrecursionlimit(100000)

def dfs(a, total): # total은 시작노드부터 a까지 오는 거리
    global mx, mx_node

    if mx < total:
        mx = total
        mx_node = a

    check[a] = 1
    for b, w in tree[a]:
        if check[b] == 0:
            dfs(b, total + w)
 
n = int(input())

tree = [[] for _ in range(n + 1)]
check = [0] * (n + 1)

for _ in range(n-1):
    a, b, w = map(int, input().split())
    tree[a].append([b, w])
    tree[b].append([a, w])

mx = -1
mx_node = -1
dfs(1, 0)

x = mx_node
check = [0] * (n + 1)
mx = -1
mx_node = -1
dfs(x, 0)

y = mx

print(y)
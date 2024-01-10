def dfs(a):
    visit[a] = 1
    for b in graph[a]:
        if not visit[b]:
            parents[b] = a
            dfs(b)
            

n = int(input())

graph = [[] for _ in range(n + 1)]

visit = [0] * (n + 1)
parents = [0] * (n + 1)

for _ in range(n - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visit[1] = 1
dfs(1)

for i in range(2, n + 1):
    print(parents[i])
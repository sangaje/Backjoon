import sys

N = int(sys.stdin.readline().rstrip())
M = int(sys.stdin.readline().rstrip())

table = {}
for i in range(1, N + 1):
    table[i] = set()

for _ in range(M):
    i, j = map(int, sys.stdin.readline().split())

    table[i].add(j)
    table[j].add(i)

visited = [False] * (N + 1)
def dfs(k):
    visited[k] = True
    cnt = 0

    for n_k in table[k]:
        if not visited[n_k]:
            cnt += dfs(n_k)

    return cnt + 1


print(dfs(1) - 1)

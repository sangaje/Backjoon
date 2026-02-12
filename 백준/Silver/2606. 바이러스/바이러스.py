import sys

N = int(sys.stdin.readline().rstrip())
M = int(sys.stdin.readline().rstrip())

table = {}
for i in range(1, N + 1):
    table[i] = set()
    table[i].add(i)

for _ in range(M):
    i, j = map(int, sys.stdin.readline().split())

    table[i].add(j)
    table[j].add(i)

for _ in range(N):
    for k, v in table.items():
        next_ks = v.copy()
        for next_k in next_ks:
            table[k] |= table[next_k]

print(len(table[1]) - 1)

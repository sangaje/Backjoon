import sys

N, M = tuple(map(int, sys.stdin.readline().rstrip().split()))
table_name = {}
table_indx = {}


for i in range(1, N + 1):
    name = sys.stdin.readline().rstrip()

    table_name[name] = i
    table_indx[i] = name

for _ in range(M):
    Q = sys.stdin.readline().rstrip()
    r = table_name.get(Q, False)
    if r:
        print(r)
    else:
        print(table_indx[int(Q)])

import sys

N, M = tuple(map(int, sys.stdin.readline().rstrip().split()))

coin = []

for _ in range(N):
    coin.append(int(sys.stdin.readline().rstrip()))

coin.reverse()

cnt = 0
for c in coin:
    cnt += M // c
    M %= c

print(cnt)

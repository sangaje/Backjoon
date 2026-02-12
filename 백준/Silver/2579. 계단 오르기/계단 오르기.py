import sys

# 1. From -1
# 2. From -2
# -> 2갈래로 나뉨
N = int(sys.stdin.readline().rstrip())
v = [int(sys.stdin.readline().rstrip()) for _ in range(N)]

dp = [[0] * (N) for _ in range(2)]
dp[0][0] = v[0]

if N > 1:
    dp[0][1] = v[1]

for i in range(N):
    # From -1
    if i + 1 < N:
        if v[i + 1] + dp[0][i] > dp[1][i + 1]:
            dp[1][i + 1] = v[i + 1] + dp[0][i]

    # From -2
    if i + 2 < N:
        if v[i + 2] + dp[0][i] > dp[0][i + 2]:
            dp[0][i + 2] = v[i + 2] + dp[0][i]
        if v[i + 2] + dp[1][i] > dp[0][i + 2]:
            dp[0][i + 2] = v[i + 2] + dp[1][i]

print(max((dp[0][-1], dp[1][-1])))

import sys

N = int(sys.stdin.readline())

dp = None


def dfs(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    elif n < 1:
        return 0

    if dp[n] == 0:
        dp[n] = dfs(n - 1) + dfs(n - 2) + dfs(n - 3)

    return dp[n]


for _ in range(N):
    n = int(sys.stdin.readline())
    dp = [0] * (n + 1)
    print(dfs(n))

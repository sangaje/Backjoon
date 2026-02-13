import sys

N = int(sys.stdin.readline())

for _ in range(N):
    n = int(sys.stdin.readline())
    dp = [0, 1, 0]

    for _ in range(n):
        next = dp[0] + dp[1]
        dp[0] = dp[1]
        dp[1] = dp[2]
        dp[2] = next

    print(dp[-1])

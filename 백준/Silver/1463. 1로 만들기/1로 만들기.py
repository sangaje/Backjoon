import sys

N = int(sys.stdin.readline().rstrip())

dp = [0x7FFF_FFFF for _ in range(N + 1)]
dp[-1] = 0

for i in range(N, 0, -1):
    if i % 2 == 0 and dp[i // 2] > dp[i] + 1:
        dp[i // 2] = dp[i] + 1

    if i % 3 == 0 and dp[i // 3] > dp[i] + 1:
        dp[i // 3] = dp[i] + 1

    if dp[i - 1] > dp[i] + 1:
        dp[i - 1] = dp[i] + 1

print(dp[1])

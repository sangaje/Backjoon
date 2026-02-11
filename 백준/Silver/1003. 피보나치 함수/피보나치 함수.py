import sys

N = int(sys.stdin.readline().rstrip())

for _ in range(N):
    X = int(sys.stdin.readline().rstrip())

    zero_dp = [0 for _ in range(50)]
    one_dp = [0 for _ in range(50)]

    zero_dp[0] = 1
    one_dp[1] = 1

    for i in range(2, 50):
        zero_dp[i] += zero_dp[i - 1] + zero_dp[i - 2]
        one_dp[i] += one_dp[i - 1] + one_dp[i - 2]

    print(zero_dp[X], one_dp[X])

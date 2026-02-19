#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, *dp;
    scanf("%d", &N);

    dp = malloc(sizeof(int) * (N + 1));
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N; i++)
        dp[i] = ((dp[i - 2] << 1) + dp[i - 1]) % 10007;

    printf("%d\n", dp[N]);

    free(dp);
    return 0;
}
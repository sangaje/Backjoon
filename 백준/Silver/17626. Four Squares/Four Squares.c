#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, *dp;
    scanf("%d", &N);

    dp = malloc(sizeof(int) * (N + 1));

    for (int i = 1; i * i <= N; i++)
        dp[i * i] = 1;

    for (int i = 1; i <= N; i++)
    {
        int bound = (i + 1) / 2;
        if (dp[i] == 1)
            continue;

        dp[i] = 10;

        for (int j = 1; j * j < i; j++)
        {
            int tmp = dp[j * j] + dp[i - (j * j)];
            if (dp[i] > tmp)
                dp[i] = tmp;
        }
    }

    printf("%d\n", dp[N]);
    free(dp);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(void)
{
        int N;
        int *dp[3];
        int *value[3];

        scanf("%d", &N);

        value[0] = malloc(sizeof(int) * N);
        value[1] = malloc(sizeof(int) * N);
        value[2] = malloc(sizeof(int) * N);

        dp[0] = malloc(sizeof(int) * N);
        dp[1] = malloc(sizeof(int) * N);
        dp[2] = malloc(sizeof(int) * N);

        bzero(dp[0], sizeof(int) * N);
        bzero(dp[1], sizeof(int) * N);
        bzero(dp[2], sizeof(int) * N);

        for (int i = 0; i < N; i++)
                scanf("%d %d %d", &value[0][i], &value[1][i], &value[2][i]);

        dp[0][0] = value[0][0];
        dp[1][0] = value[1][0];
        dp[2][0] = value[2][0];

        for (int i = 1; i < N; i++)
        {
                for (int j = 0; j < 3; j++)
                {
                        for (int k = 0; k < 3; k++)
                        {
                                if (j == k)
                                        continue;
                                int tmp = value[j][i] + dp[k][i - 1];
                                if (!dp[j][i] || dp[j][i] > tmp)
                                        dp[j][i] = tmp;
                        }
                }
        }
        int min = 0xFFFFFFF;
        for (int i = 0; i < 3; i++)
        {
                if (dp[i][N - 1] < min)
                        min = dp[i][N - 1];
        }

        printf("%d\n", min);

        free(value[0]);
        free(value[1]);
        free(value[2]);
        free(dp[0]);
        free(dp[1]);
        free(dp[2]);

        return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    int *prefix_sum = malloc(sizeof(int) * (N + 1));

    prefix_sum[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &prefix_sum[i]);
        prefix_sum[i] += prefix_sum[i - 1];
    }

    for (int i = 0; i < M; i++)
    {
        int from, to, total = 0;
        scanf("%d %d", &from, &to);

        printf("%d\n", prefix_sum[to] - prefix_sum[from - 1]);
    }

    free(prefix_sum);
    return 0;
}
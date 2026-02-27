#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int N, M;
        long long int *woods;
        scanf("%d %d", &N, &M);

        int l = 1, r = 0;
        woods = malloc(sizeof(long long int) * N);

        for (int i = 0; i < N; i++)
        {
                scanf("%lld", &woods[i]);
                if (r < woods[i])
                        r = woods[i];
        }

        while (l <= r)
        {
                int mid = (l + r) / 2;
                long long int total = 0;

                for (int i = 0; i < N; i++)
                        total += woods[i] - mid > 0 ? woods[i] - mid : 0;

                if (total < M)
                        r = mid - 1;
                else
                        l = mid + 1;
        }

        printf("%d\n", l - 1);

        return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int K, N, max = 0;
        unsigned int *wires;
        scanf("%d %d", &K, &N);
        wires = malloc(sizeof(int) * K);

        for (int i = 0; i < K; i++)
        {
                scanf("%d", &wires[i]);
                if (max < wires[i])
                        max = wires[i];
        }

        unsigned int l = 1, r = max + 1, m, total;

        while (l <= r)
        {
                total = 0;
                if (!(m = (l + r) / 2))
                        break;
                for (int i = 0; i < K; i++)
                {
                        total += wires[i] / m;
                }

                if (total >= N)
                        l = m + 1;
                else
                        r = m - 1;
        }

        printf("%d\n", l - 1);
        free(wires);

        return 0;
}
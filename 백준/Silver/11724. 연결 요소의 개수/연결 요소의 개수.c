#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int N, M, *currs, *ends, *edges, *src, *dst;

void dfs(int v)
{
        if (currs[v])
                return;
        currs[v] = 1;
        for (int i = ends[v - 1]; i < ends[v]; i++)
                dfs(edges[i]);
}

int main(void)
{
        scanf("%d %d", &N, &M);

        ends = malloc(sizeof(int) * (N + 1));
        edges = malloc(sizeof(int) * M * 2);

        src = malloc(sizeof(int) * M);
        dst = malloc(sizeof(int) * M);
        currs = malloc(sizeof(int) * (N + 1));

        bzero(ends, sizeof(int) * (N + 1));
        bzero(currs, sizeof(int) * (N + 1));
        for (int i = 0; i < M; i++)
        {
                int u, v;
                scanf("%d %d", &u, &v);

                src[i] = u;
                dst[i] = v;
                ends[u]++;
                ends[v]++;
        }

        for (int i = 0; i < N; i++)
                ends[i + 1] += ends[i];

        for (int i = 0; i < M; i++)
        {
                edges[ends[src[i] - 1] + (currs[src[i]]++)] = dst[i];
                edges[ends[dst[i] - 1] + (currs[dst[i]]++)] = src[i];
        }
        bzero(currs, sizeof(int) * (N + 1));
        int total = 0;

        for (int i = 1; i <= N; i++)
        {
                if (currs[i])
                        continue;
                total++;
                dfs(i);
        }
        printf("%d\n", total);

        free(src);
        free(dst);
        free(currs);

        free(ends);
        free(edges);
        return 0;
}
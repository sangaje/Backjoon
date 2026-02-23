#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int N, M, V;
int *start;
int *to;
int *visited;

int _cmp(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

void DFS(int v)
{

        visited[v] = 1;
        printf("%d ", v);
        for (int i = start[v - 1]; i < start[v]; i++)
        {
                if (!visited[to[i]])
                        DFS(to[i]);
        }
}

void BFS(int v)
{
        int queue[1000] = {
            0,
        };
        int head = 0, tail = 1;
        visited[v] = 1;
        queue[head] = v;

        while (head != tail)
        {
                for (head; head < tail; head++)
                {
                        v = queue[head];
                        printf("%d ", v);

                        for (int i = start[v - 1]; i < start[v]; i++)
                        {
                                if (!visited[to[i]])
                                {
                                        visited[to[i]] = 1;
                                        queue[tail++] = to[i];
                                }
                        }
                }
        }
}

int main(void)
{
        scanf("%d %d %d", &N, &M, &V);

        start = malloc(sizeof(int) * (N + 1));
        visited = malloc(sizeof(int) * (N + 1));
        to = malloc(sizeof(int) * M * 2);

        int *u = malloc(sizeof(int) * M);
        int *v = malloc(sizeof(int) * M);
        int *deg = malloc(sizeof(int) * (N + 1));

        bzero(start, sizeof(int) * (N + 1));
        bzero(deg, sizeof(int) * (N + 1));

        for (int i = 0; i < M; i++)
        {
                scanf("%d %d", u + i, v + i);
                start[u[i]]++;
                start[v[i]]++;
        }

        for (int i = 0; i < N; i++)
                start[i + 1] += start[i];

        for (int i = 0; i < M; i++)
        {
                to[start[u[i] - 1] + deg[u[i]]++] = v[i];
                to[start[v[i] - 1] + deg[v[i]]++] = u[i];
        }

        free(u);
        free(v);
        free(deg);
        for (int v = 1; v <= N; v++)
                qsort(&to[start[v - 1]], start[v] - start[v - 1], sizeof(int), _cmp);

        // Init Graph End
        bzero(visited, sizeof(int) * (N + 1));
        DFS(V);
        printf("\n");
        bzero(visited, sizeof(int) * (N + 1));
        BFS(V);
        printf("\n");

        // END

        free(to);
        free(start);
        free(visited);

        return 0;
}
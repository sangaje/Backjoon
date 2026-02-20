#include <stdio.h>
#include <stdlib.h>

typedef struct _pos_t
{
        unsigned char x;
        unsigned char y;
} pos_t;

#define empty(_x) ((_x).x == 0 && (_x).y == 0)
#define is_same(_x, _y) (((_x).x == (_y).x) && ((_x).y == (_y).y))

pos_t find_root(pos_t table[51][51], pos_t pos)
{
        while (!is_same(table[pos.x][pos.y], pos))
        {
                pos = table[pos.x][pos.y];
        }

        return pos;
}

int solve(int M, int N, int K)
{
        int cnt = 0;
        pos_t table[51][51] = {
            0,
        };

        for (int i = 0; i < K; i++)
        {
                int x, y, is_new;
                scanf("%d %d", &x, &y);
                x++;
                y++;
                table[x][y].x = x;
                table[x][y].y = y;

                if (x > 0 && !empty(table[x - 1][y]))
                {
                        pos_t root = find_root(table, table[x - 1][y]);
                        table[root.x][root.y] = table[x][y];
                }
                if (y > 0 && !empty(table[x][y - 1]))
                {
                        pos_t root = find_root(table, table[x][y - 1]);
                        table[root.x][root.y] = table[x][y];
                }
                if (x < M - 1 && !empty(table[x + 1][y]))
                {
                        pos_t root = find_root(table, table[x + 1][y]);
                        table[root.x][root.y] = table[x][y];
                }
                if (y < N - 1 && !empty(table[x][y + 1]))
                {
                        pos_t root = find_root(table, table[x][y + 1]);
                        table[root.x][root.y] = table[x][y];
                }
        }
        for (int i = 1; i <= M; i++)
        {
                for (int j = 1; j <= N; j++)
                {
                        pos_t pos = {.x = i, .y = j};
                        if (is_same(table[pos.x][pos.y], pos))
                                cnt++;
                }
        }
        return cnt;
}

int main(void)
{
        int M, N, K, _rept;
        scanf("%d", &_rept);

        for (int _ = 0; _ < _rept; _++)
        {
                scanf("%d %d %d", &M, &N, &K);
                printf("%d\n", solve(M, N, K));
        }

        return 0;
}
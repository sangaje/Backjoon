#include <stdio.h>
#include <stdlib.h>

int dfs(char **board, int x, int y, int N, int M)
{
        if (board[x][y] == 'X')
                return 0;

        int retv = board[x][y] == 'P' ? 1 : 0;
        board[x][y] = 'X';

        if (x + 1 < N)
                retv += dfs(board, x + 1, y, N, M);
        if (x - 1 >= 0)
                retv += dfs(board, x - 1, y, N, M);
        if (y + 1 < M)
                retv += dfs(board, x, y + 1, N, M);
        if (y - 1 >= 0)
                retv += dfs(board, x, y - 1, N, M);
        return retv;
}

int main(void)
{
        char **board;
        int N, M, x, y;
        scanf("%d %d", &N, &M);
        board = malloc(sizeof(char *) * N);
        *board = malloc(sizeof(char) * N * M);

        for (int i = 1; i < N; i++)
        {
                board[i] = *board + M * i;
        }

        for (int i = 0; i < N; i++)
        {
                for (int j = 0; j < M; j++)
                {
                        scanf(" %c", &board[i][j]);
                        if (board[i][j] == 'I')
                        {
                                x = i;
                                y = j;
                        }
                }
        }
        int result = dfs(board, x, y, N, M);

        if (!result)
                printf("TT\n");
        else
                printf("%d\n", result);

        free(*board);
        free(board);

        return 0;
}
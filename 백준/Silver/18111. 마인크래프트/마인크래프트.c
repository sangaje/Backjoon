#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(void)
{
        int N, M, B, **board, max = 0;
        scanf("%d %d %d", &N, &M, &B);
        board = malloc(sizeof(int *) * N);
        board[0] = malloc(sizeof(int) * N * M);

        for (int i = 1; i < N; i++)
        {
                board[i] = *board + M * i;
        }

        for (int i = 0; i < N; i++)
        {
                for (int j = 0; j < M; j++)
                {
                        scanf("%d", &board[i][j]);
                        if (board[i][j] > max)
                                max = board[i][j];
                }
        }

        int target = max, min_x = 0x7fffffff, min_y = 0x7fffffff;
        int min_target = max;
        while (target >= 0)
        {
                int x = 0, y = 0;
                for (int i = 0; i < N; i++)
                {
                        for (int j = 0; j < M; j++)
                        {
                                if (target > board[i][j])
                                        x += target - board[i][j];

                                else if (target < board[i][j])
                                        y += board[i][j] - target;
                        }
                }
                if (B + y < x)
                        goto end_loop;
                if (x + 2 * y < min_x + 2 * min_y)
                {
                        min_target = target;
                        min_x = x;
                        min_y = y;
                }
        end_loop:
                target--;
        }

        printf("%d %d\n", min_x + 2 * min_y, min_target);

        free(*board);
        free(board);

        return 0;
}
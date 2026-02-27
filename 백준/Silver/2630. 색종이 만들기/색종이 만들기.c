#include <stdio.h>
#include <stdlib.h>

unsigned long long int fold(char **board, size_t size, int x, int y)
{
        unsigned long long int retv = 0;
        int is_all_black = 1, is_all_white = 1;
        int bound_x = x + size, bound_y = y + size;

        for (int i = x; i < bound_x; i++)
        {
                for (int j = y; j < bound_y; j++)
                {
                        if (board[i][j])
                                is_all_black = 0;
                        else
                                is_all_white = 0;
                }
        }
        if (is_all_black)
                retv += (unsigned long long int)1 << 32;
        else if (is_all_white)
                retv += 1;
        else if (!(is_all_black || is_all_white))
        {
                size_t next_size = size >> 1;
                retv += fold(board, next_size, x, y);
                retv += fold(board, next_size, x + next_size, y);
                retv += fold(board, next_size, x, y + next_size);
                retv += fold(board, next_size, x + next_size, y + next_size);
        }
        return retv;
}

int main(void)
{
        int N;
        char **board;
        scanf("%d", &N);

        board = malloc(sizeof(char *) * N);
        board[0] = malloc(sizeof(char) * N * N);
        char buff[300];
        for (int i = 0; i < N; i++)
        {
                board[i] = board[0] + i * N;
                for (int j = 0; j < N; j++)
                {
                        char c;
                        do
                                c = getchar();
                        while (c != '0' && c != '1');
                        board[i][j] = c == '1' ? 1 : 0;
                }
        }
        unsigned long long int result = fold(board, N, 0, 0);
        printf("%lld\n", result >> 32);
        printf("%lld\n", result & 0xFFFFFFFF);

        free(board[0]);
        free(board);

        return 0;
}
#include <stdio.h>

#define N 51

int main(void)
{
        char buff[N];
        scanf("%s", buff);

        char *curr = buff;
        char tmp;
        int num = 0, total = 0;
        int is_minus = 0;

        while (tmp = *curr++)
        {
                if ('0' <= tmp && tmp <= '9')
                {
                        num *= 10;
                        num += tmp - '0';
                }
                else
                {
                        if (is_minus)
                                total -= num;
                        else
                                total += num;
                        if (tmp == '-')
                                is_minus = 1;
                        num = 0;
                }
        }
        if (is_minus)
                total -= num;
        else
                total += num;

        printf("%d\n", total);

        return 0;
}
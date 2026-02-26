#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int N, n, tail = 0;
        scanf("%d", &N);

        int *heap = malloc(sizeof(int) * (N + 1));

        for (int _ = 0; _ < N; _++)
        {
                scanf("%d", &n);
                if (n)
                {
                        int curr = tail++;
                        heap[curr] = n;

                        while (curr)
                        {
                                curr = (curr - 1) / 2;
                                int l = curr * 2 + 1;
                                int r = l + 1;
                                int min = r < tail && heap[r] < heap[l] ? r : l;
                                if (heap[curr] <= heap[min])
                                        break;
                                int tmp = heap[curr];
                                heap[curr] = heap[min];
                                heap[min] = tmp;
                        }

                        continue;
                }

                if (!tail)
                {
                        printf("0\n");
                        continue;
                }

                printf("%d\n", heap[0]);
                heap[0] = heap[--tail];
                int curr = 0;
                while (curr < tail)
                {
                        int l = curr * 2 + 1;
                        int r = l + 1;
                        if (l >= tail)
                                break;

                        int min = r < tail && heap[r] < heap[l] ? r : l;

                        if (heap[curr] < heap[min])
                                break;

                        int tmp = heap[curr];
                        heap[curr] = heap[min];
                        heap[min] = tmp;
                        curr = min;
                }
        }

        free(heap);

        return 0;
}
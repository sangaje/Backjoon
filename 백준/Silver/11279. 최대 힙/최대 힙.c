#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int N, *heap, n, tail = 0;
        scanf("%d", &N);

        heap = malloc(sizeof(int) * N);
        for (int _ = 0; _ < N; _++)
        {
                scanf("%d", &n);
                if (n)
                {
                        int curr = tail;
                        heap[tail++] = n;

                        while (curr)
                        {
                                int parent = (curr - 1) >> 1;
                                if (heap[curr] > heap[parent])
                                {
                                        heap[curr] ^= heap[parent];
                                        heap[parent] ^= heap[curr];
                                        heap[curr] ^= heap[parent];
                                }
                                else
                                        break;

                                curr = parent;
                        }

                        continue;
                }
                if (tail)
                {
                        printf("%d\n", heap[0]);
                        heap[0] = heap[--tail];
                        int curr = 0;

                        while (1)
                        {
                                int l = (curr << 1) + 1, r = l + 1;

                                if (l >= tail)
                                        break;

                                int max = r < tail ? (heap[l] > heap[r] ? l : r) : l;

                                if (heap[curr] < heap[max])
                                {
                                        heap[curr] ^= heap[max];
                                        heap[max] ^= heap[curr];
                                        heap[curr] ^= heap[max];
                                }
                                else
                                        break;
                                curr = max;
                        }

                        continue;
                }
                printf("0\n");
        }

        return 0;
}
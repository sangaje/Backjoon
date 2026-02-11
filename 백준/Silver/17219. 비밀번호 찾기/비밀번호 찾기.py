import sys
from time import sleep

N, M = tuple(map(int, (sys.stdin.readline().rstrip().split())))
table = {}

for _ in range(N):
    site, passwd = sys.stdin.readline().rstrip().split()

    table[site] = passwd
for _ in range(M):
    site = sys.stdin.readline().rstrip()

    print(table[site])

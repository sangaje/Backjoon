import sys

N = int(sys.stdin.readline())

T = list(map(int, sys.stdin.readline().rstrip().split()))

T.sort()
total = 0
for i in range(len(T)):
    total +=  (len(T) - i) * T[i]

print(total)
    
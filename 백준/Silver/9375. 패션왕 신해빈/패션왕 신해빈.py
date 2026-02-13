import sys

N = int(sys.stdin.readline())

for _ in range(N):
    n = int(sys.stdin.readline())
    data = {}

    for _ in range(n):
        name, type = sys.stdin.readline().split()
        tmp = data.get(type, 1)
        tmp += 1
        data[type] = tmp

    r = 1
    for k, v in data.items():
        r *= v

    print(r - 1)

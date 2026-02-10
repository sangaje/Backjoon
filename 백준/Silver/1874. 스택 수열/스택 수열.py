import sys

N = int(sys.stdin.readline())

nums = [int(sys.stdin.readline()) for _ in range(N)]
result = []
stack = [0]
i = 1

for n in nums:
    while n > stack[-1]:
        stack.append(i)
        result.append("+")
        i += 1
    if n < stack[-1]:
        print("NO")
        exit(0)
    result.append("-")
    stack.pop()

for c in result:
    sys.stdout.write(f"{c}\n")

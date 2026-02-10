import sys

num = int(sys.stdin.readline())

for _ in range(num):
    N, T = tuple(map(int, sys.stdin.readline().split()))

    nums = list(map(int, sys.stdin.readline().split()))

    count = 0

    while len(nums):
        current = nums[0]
        if current == max(nums):
            count += 1
            if T == 0:
                print(count)
                break
            nums.pop(0)
            N -= 1

        else:
            tmp = nums.pop(0)
            nums.append(tmp)
        T -= 1
        T %= N

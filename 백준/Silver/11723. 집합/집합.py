import sys

set = [False for _ in range(21)]


def add(x):
    global set

    set[x] = True


def remove(x):
    global set

    set[x] = False


def check(x):
    sys.stdout.write(f"{1 if set[x] else 0}\n")


def toggle(x):
    global set

    if set[x]:
        set[x] = False
    else:
        set[x] = True


def all(x):
    global set

    set = [True for _ in range(21)]


def empty(x):
    global set

    set = [False for _ in range(21)]


operations = {
    "add": add,
    "remove": remove,
    "check": check,
    "toggle": toggle,
    "all": all,
    "empty": empty,
}

N = int(sys.stdin.readline())

for _ in range(N):
    op = sys.stdin.readline().rstrip()

    if op in ["all", "empty"]:
        x = 0
    else:
        op, x = tuple(op.split())

    x = int(x)
    operations[op](x)

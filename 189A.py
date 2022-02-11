import sys
from functools import lru_cache


@lru_cache
def calc(n, v):
    return 0 if n == 0 else max(
        (calc(n - i, v) + 1 for i in v if n >= i), default=float("-inf"))


def main():
    n, a, b, c = map(int, input().split())
    print(calc(n, (a, b, c)))


if __name__ == "__main__":
    try:
        with open("_input.txt", "r") as inf, open("_output.txt", "w") as outf:
            sys.stdin = inf
            sys.stdout = outf
            main()
    except:
        main()
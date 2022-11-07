from math import gcd, isinf
import sys
from functools import lru_cache, reduce


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        g = reduce(gcd, arr, 0)
        if g == 1:
            print(0)
        elif gcd(g, n) == 1:
            print(1)
        elif gcd(g, n-1) == 1:
            print(2)
        else:
            print(3)


if __name__ == "__main__":
    # with open("_input.txt", "r") as inf, open("_output.txt", "w") as outf:
    #     sys.stdin = inf
    #     sys.stdout = outf
    main()

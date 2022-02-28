# from functools import lru_cache
from collections import Counter
import sys


arr = list()


# @lru_cache
# def mex(l, r):
#     return sorted(set(range(r-l+2)) - set(arr[l:r+1]))[0]


# @lru_cache
def calc(l, r):
    # if l == r:
    #     return 1 + int(arr[l] == 0)
    # return max(1 + mex(l, r), *(calc(l, i) + calc(i+1, r) for i in range(l, r)))
    return r - l + 1 + Counter(arr[l:r+1])[0]


def run():
    n = int(input())
    arr.clear()
    arr.extend(map(int, input().split()))
    # for i in range(n):
    #     for j in range(i, n):
    #         print(i, j, arr[i:j+1], calc(i, j))
    print(sum(calc(i, j) for i in range(n) for j in range(i, n)))
    # calc.cache_clear()
    # mex.cache_clear()


def main():
    t = int(input())
    for _ in range(t):
        run()


if __name__ == "__main__":
    # with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
    #     sys.stdin = fin
    #     sys.stdout = fout
    #     main()
    main()

import sys
from functools import lru_cache


def run():
    n, x = map(int, input().split())
    arr = list(map(int, input().split()))

    @lru_cache
    def dp(i, k):
        if i == len(arr):
            return 0
        return max(arr[i] + x + dp(i+1, k-1) if k else 0,
                   arr[i] + dp(i+1, k), arr[i], 0)
    print(*(max(dp(j, i) for j in range(n, -1, -1)) for i in range(n+1)))


def main():
    t = int(input())
    for _ in range(t):
        run()


if __name__ == "__main__":
    try:
        with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
            sys.stdin = fin
            sys.stdout = fout
            main()
    except IOError:
        main()

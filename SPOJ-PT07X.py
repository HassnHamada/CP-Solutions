from functools import lru_cache
import sys


def main():
    n = int(input())
    tre = dict()
    for i in range(n - 1):
        u, v = map(int, input().split())
        if u not in tre:
            tre[u] = set()
        if v not in tre:
            tre[v] = set()
        tre[u].add(v)
        tre[v].add(u)

    # @lru_cache
    def solve(n, p):
        ret = (1, -1)
        l = list()
        for i in tre[n]:
            if i == p:
                continue
            l.append(solve(i, n, p ^ 1))
        mn = float("inf")
        for i in l:
            mn = min(mn, i[])
        return ret

    if n == 1:
        print(1)
    else:
        ans = solve(1, 0, 0)
        assert(min(ans, n - ans) == min(min(solve(i+1, 0, 0), solve(i+1, 0, 1)) for i in range(n)))


if __name__ == "__main__":
    with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
        sys.stdin = fin
        sys.stdout = fout
        main()
    # main()

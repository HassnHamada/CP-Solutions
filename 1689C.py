from bisect import bisect_left, bisect_right
from collections import Counter, deque
# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")


t = int(input())
for _ in range(t):
    n = int(input())
    tre = [list() for _ in range(n)]
    sz = [0 for _ in range(n)]
    for i in range(n - 1):
        u, v = map(int, input().split())
        tre[u - 1].append(v - 1)
        tre[v - 1].append(u - 1)

    def calc_sz(c, p=-1):
        sz[c] = 1
        if p in tre[c]:
            tre[c].remove(p)
        for i in tre[c]:
            assert i != p
            sz[c] += calc_sz(i, c)
        return sz[c]

    def ans(c):
        if len(tre[c]) == 0:
            return 0
        elif len(tre[c]) == 1:
            return sz[tre[c][0]] - 1
        elif len(tre[c]) == 2:
            return max(sz[tre[c][0]] - 1 + ans(tre[c][1]),
                       sz[tre[c][1]] - 1 + ans(tre[c][0]))
        assert False

    calc_sz(0)
    print(ans(0))

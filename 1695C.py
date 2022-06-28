from bisect import bisect_left, bisect_right
from collections import Counter, deque
# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")


t = int(input())
for _ in range(t):
    # n = int(input())
    n, m = map(int, input().split())
    mat = list(list(map(int, input().split())) for _ in range(n))
    ans = list(list(set() for _ in range(m)) for _ in range(n))
    ans[-1][-1].add(mat[-1][-1])
    for i in range(n - 2, -1, -1):
        ans[i][-1] = set(k + mat[i][-1] for k in ans[i + 1][-1])
    for j in range(m - 2, -1, -1):
        ans[-1][j] = set(k + mat[-1][j] for k in ans[-1][j + 1])
    for i in range(n - 2, -1, -1):
        for j in range(m - 2, -1, -1):
            ans[i][j] = ans[i + 1][j] | ans[i][j + 1]
            ans[i][j] = set(k + mat[i][j] for k in ans[i][j])
    print("YES" if 0 in ans[0][0] else "NO")

from bisect import bisect_left, bisect_right
from collections import Counter, deque
# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")


t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    mat = list(list(map(int, input().split())) for _ in range(n))
    mx = max(max(i) for i in mat)
    def ans():
        for i in range(n):
            for j in range(m):
                if mx == mat[i][j]:
                    return max(i + 1, n - i) * max(j + 1, m - j)
    print(ans())
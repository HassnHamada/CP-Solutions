from bisect import bisect_left, bisect_right
from collections import Counter, deque
import sys

sys.stdin = open("_input.txt", "r")
sys.stdout = open("_output.txt", "w")

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    www = list(map(int, input().split()))
    ccc = list(map(int, input().split()))
    for i, v in enumerate(www):
        v = bin(v)[2:]
        www[i] = len(v) + v.count('1') - 2
    print(www)
    mx = max(www)
    if k < sum(www):
        dp = dict()
        for i in range(n-1, -1, -1):
            for j in range(0, k+1):
                dp[(i, j)] = dp[(i+1, j)] if (i+1, j) in dp else 0
                if j >= www[i] and i + 1 != n:
                    dp[(i, j)] = max(dp[(i, j)], dp[(i+1, j-www[i])] + ccc[i])
                    # if (i+1, j-www[i]) in dp:
                    # else:
                    #     dp[(i, j)] = max(dp[(i, j)], ccc[i])
        print(dp[(0, k)])
    else:
        print(sum(ccc))


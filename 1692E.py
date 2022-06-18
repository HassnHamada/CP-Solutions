from bisect import bisect_left, bisect_right
from collections import Counter, deque
# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")


t = int(input())
for _ in range(t):
    # n = int(input())
    n, s = map(int, input().split())
    inp = list(map(int, input().split()))
    acc = [inp[0]]
    for i in inp:
        acc.append(acc[-1] + i)
    ans = -1
    if acc[-1] >= s:
        ans= float('inf')
        for i in range(n-1, 0, -1):
            pass
    print(ans)

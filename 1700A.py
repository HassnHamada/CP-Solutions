from bisect import bisect_left, bisect_right
from collections import Counter, deque
# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")


t = int(input())
for _ in range(t):
    # n, num = int(input()), int(input())
    n, m = map(int, input().split())
    # arr = list(map(int, input().split()))
    # mat = list(list(map(int, input().split())) for _ in range(n))
    # ans = m * (m + 1) // 2 + m * (n - 1) + sum(i * m for i in range(1, n))
    print(m * (m + 1) // 2 + m * (n - 1) + n * (n - 1) // 2 * m)

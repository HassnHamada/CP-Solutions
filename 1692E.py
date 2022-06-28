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
    acc = [0]
    for i in inp:
        acc.append(acc[-1] + i)
    print(min(n - i + bisect_left(acc, acc[i] - s)
              for i in range(n, 0, -1) if acc[i] >= s)
          if acc[-1] >= s else -1)

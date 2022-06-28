from bisect import bisect_left, bisect_right
from collections import Counter, deque
# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")


t = int(input())
for _ in range(t):
    n = int(input())
    inp = set(map(int, input().split()))
    print(len(inp) if (n - len(inp)) % 2 == 0 else len(inp) - 1)

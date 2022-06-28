from bisect import bisect_left, bisect_right
from collections import Counter, deque
# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")


t = int(input())
for _ in range(t):
    n, num = int(input()), int(input())
    # n, m = map(int, input().split())
    # arr = list(map(int, input().split()))
    # mat = list(list(map(int, input().split())) for _ in range(n))
    org = num
    num = list(str(num + 2 * 10**(n - 1)))
    n = len(num)
    num[n//2 + n % 2:] = num[:n//2][::-1]
    print(int("".join(num)) - org)

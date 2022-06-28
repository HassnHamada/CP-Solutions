from bisect import bisect_left, bisect_right
from collections import Counter, deque
# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")


t = int(input())
for _ in range(t):
    n = int(input())
    # n, m = map(int, input().split())
    # mat = list(list(map(int, input().split())) for _ in range(n))
    arr = list(map(int, input().split()))
    mn = min(arr)
    ind = arr.index(mn)
    # arr = list(i % mn for i in arr)

    # def ans():
    #     mike = mn * n % 2 == 0
    #     for i in arr:
    #         if i == 0:
    #             return not mike
    #         mike = not mike
    print("Mike" if n % 2 == 1 or ind % 2 == 1 else "Joe")

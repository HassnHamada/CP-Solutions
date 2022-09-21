from functools import lru_cache
# import sys


# sys.stdin = open("_input.txt", 'r')
# sys.stdout = open("_output.txt", 'w')

N = int(5e4)

k, p = map(int, input().split())
arr = list(map(int, input().split()))

ans = [0] * N


def solve(v):
    ans[v - 1] = min(ans[v - i - 1] if v - i > 0 else i - v for i in arr)


for i in range(N):
    solve(i + 1)

for _ in range(k):
    print(ans[int(input()) - 1])

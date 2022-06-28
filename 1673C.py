from bisect import bisect_left, bisect_right
from collections import Counter, deque
# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")

N, MOD = int(4e4 + 10), int(1e9+7)
pal = list(i for i in range(1, N) if str(i) == str(i)[::-1])
dp = [0] * N
dp[0] = 1
for i in pal:
    for j in range(i, N):
        dp[j] = (dp[j] + dp[j - i]) % MOD
t = int(input())
for _ in range(t):
    n = int(input())
    print(dp[n])

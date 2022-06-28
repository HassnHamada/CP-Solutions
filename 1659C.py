from bisect import bisect_left, bisect_right
from collections import Counter, deque
# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")

t = int(input())
for _ in range(t):
    n, a, b = map(int, input().split())
    arr = [0]
    arr.extend(map(int, input().split()))
    cst = list(b*i for i in arr)
    for i in range(1, n+1):
        cst[i] += cst[i-1]
    ind, ans = 0, cst[-1]
    for i in range(1, n):
        if a*(arr[i]-arr[ind]) < (n - i) * b*(arr[i] - arr[ind]):
            ans += a*(arr[i]-arr[ind]) - (n - i) * b*(arr[i] - arr[ind])
            ind = i
    print(ans)

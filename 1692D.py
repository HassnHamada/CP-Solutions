from bisect import bisect_left, bisect_right
from collections import Counter, deque
# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")


t = int(input())
for _ in range(t):
    tim, x = input().split()
    x = int(x)
    h, m = map(int, tim.split(':'))
    ch, cm = h, m
    ans = 0
    while True:
        if ch % 10 == cm // 10 and ch // 10 == cm % 10:
            ans += 1
        ch, cm = (ch + (x + cm) // 60) % 24, (x + cm) % 60
        if ch == h and cm == m:
            break
    print(ans)

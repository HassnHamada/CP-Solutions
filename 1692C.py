from bisect import bisect_left, bisect_right
from collections import Counter, deque
# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")


t = int(input())
for _ in range(t):
    input()
    brd = list(input() for i in range(8))
    for i in range(1, 7):
        for j in range(1, 7):
            if brd[i][j] == brd[i+1][j-1] == brd[i+1][j+1] == brd[i-1][j-1] == brd[i-1][j+1] == '#' and brd[i-1][j] == brd[i+1][j] == brd[i][j-1] == brd[i][j+1] == '.':
                print(i + 1, j + 1)

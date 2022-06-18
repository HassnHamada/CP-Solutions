# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    tot = sum(map(int, input().split()))
    print(max(0, tot - m))

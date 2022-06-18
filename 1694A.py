# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    c = min(a, b)
    a -= c
    b -= c
    print("10" * c + ("0" * a if a else "1" * b))

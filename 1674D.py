import sys


def run():
    n = int(input())
    arr = list(map(int, input().split()))
    if n <= 2:
        print("YES")
        return
    a, b = arr.pop(), arr.pop()
    if b < a:
        a, b = b, a
    while len(arr) >= 2:
        c, d = arr.pop(), arr.pop()
        if d < c:
            c, d = d, c
        if a < d:
            print("NO")
            return
        a, b = c, d
    if len(arr) and a < arr[0]:
        print("NO")
        return
    print("YES")


# with open("_input.txt", 'r') as fin, open("_output.txt", 'w') as fout:
#     sys.stdin = fin
#     sys.stdout = fout
t = int(input())
for _ in range(t):
    run()
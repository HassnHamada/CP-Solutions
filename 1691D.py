# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")

t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    v = mx = max(arr[0], 0)
    ok = True
    t = list()
    for i in range(1, n):
        t.append((v, mx))
        mx = max(mx, arr[i])
        v += arr[i]
        if v <= 0:
            mx = v = 0
    t.append((v, mx))
    v = mx = max(arr[-1], 0)
    for i in range(n-2, -1, -1):
        t.append((v, mx))
        mx = max(mx, arr[i])
        v += arr[i]
        if v <= 0:
            mx = v = 0
    t.append((v, mx))
    print("YES" if all(i <= j for i, j in t) else "NO")

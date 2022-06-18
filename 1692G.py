# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")

t = int(input())
for _ in range(t):
    # n = int(input())
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.append(0)
    ans, sz = 0, 1
    for i in range(n):
        a, b = arr[i], arr[i+1]
        if 2*b > a:
            sz += 1
        else:
            ans += max(0, sz - k)
            sz = 1
    print(ans)

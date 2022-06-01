# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    arr = list(input())
    if arr[-1] != '1':
        for i in range(n-2, max(n-2-k, -1), -1):
            if arr[i] == '1':
                k -= n - i - 1
                arr[i], arr[-1] = arr[-1], arr[i]
                break
    if arr[0] != '1':
        for i in range(1, min(k+1, n-1)):
            if arr[i] == '1':
                k -= i
                arr[i], arr[0] = arr[0], arr[i]
                break
    ans = 0
    arr = "".join(arr)
    # print(arr, k)
    for i in range(n-1):
        ans += int(arr[i:i+2])
    print(ans)

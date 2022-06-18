# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")

t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    while len(arr) and arr[-1] == 0:
        arr.pop()
    if len(arr) == 0:
        ok = True
    else:
        ok = sum(arr) == 0
        if ok:
            n = len(arr)
            vvv = [0] * n
            for i, v in enumerate(arr):
                if i == n - 1:
                    break
                if arr[i] <= vvv[i]:
                    ok = False
                    break
                vvv[i + 1] -= arr[i] - vvv[i]
                vvv[i] = arr[i]
            ok = ok and vvv[n-1] == arr[n-1] 
    print("Yes" if ok else "No")

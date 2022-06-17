import sys

sys.stdin = open("_input.txt", "r")
sys.stdout = open("_output.txt", "w")

t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    arr = [i for i in arr if i != 0]
    n = len(arr)
    if n == 0:
        print("YES")
        continue
    if any(arr[i-1] > 0 and arr[i] > 0 for i in range(1, n)):
        print("NO")
        continue
    ii = jj = 0
    while ii < n:
        assert arr[ii] != 0
        arr[jj] = arr[ii]
        ii += 1
        if arr[jj] < 0:
            while ii < n and arr[ii] < 0:
                arr[jj] += arr[ii]
                ii += 1
        jj += 1
    n = jj
    arr = arr[:n]
    # print(arr)
    # s, e = 0, n
    # while s < n and arr[s] < 0:
    #     s += 1
    # while e > s and arr[e-1] < 0:
    #     e -= 1
    # print(s, e)
    # if e-s <= 1:
    #     print("YES")
    #     continue
    # ok = True
    # v = mx = 0
    # for i in range(s, e):
    #     mx = max(mx, arr[i])
    #     v += arr[i]
    #     if arr[i] > 0:
    #         if v > mx:
    #             ok = False
    #     elif v < 0:
    #         v = mx = 0
    # v = mx = 0
    # for i in range(e-1, s-1, -1):
    #     mx = max(mx, arr[i])
    #     v += arr[i]
    #     if arr[i] > 0:
    #         if v > mx:
    #             ok = False
    #     elif v < 0:
    #         v = mx = 0
    # print("YES" if ok else "NO")

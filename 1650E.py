import sys


def run():
    input()
    n, d = map(int, input().split())
    arr = [0]
    arr.extend(list(map(int, input().split())))
    arr.append(d+1)
    mx = (0, 0)
    mn = (0, n+1)
    for i in range(2, n+1):
        if arr[mx[1]] - arr[mx[0]] < arr[i] - arr[i-1]:
            mx = (i-1, i)
        if arr[mn[1]] - arr[mn[0]] > arr[i] - arr[i-1]:
            mn = (i-1, i)
    # print(mx)
    # mx = mx if arr[mx[1]] - arr[mx[0]] > arr[mn[1]] - \
    #     arr[mn[0]-1] else (mn[0]-1, mn[1])
    # print(mx)
    # mx = mx if arr[mx[1]] - arr[mx[0]] > arr[mn[1]+1] - \
    #     arr[mn[0]] else (mn[0], mn[1]+1)
    # print(mx)
    # print(arr)
    # if mx_t[0] == 0:
    #     ans = arr[1] - 1
    # elif mx[1] == n+1:
    #     ans = arr[n] - 1
    # else:
    #     ans = (arr[mx[1]] - arr[mx[0]]) // 2
    print(mx, mn)
    if mn[0] == 1:
        ans = max((arr[mx[1]] - arr[mx[0]] - 1) // 2,
                  (arr[mn[1]+1] - arr[mn[0]] - 1) // 2,
                  arr[mn[1]] - 2)
    elif mn[1] == n:
        ans = max((arr[mx[1]] - arr[mx[0]] - 1) // 2,
                  (arr[mn[1]] - arr[mn[0]-1] - 1) // 2,
                  n - arr[mn[0]])
    else:
        ans = max((arr[mx[1]] - arr[mx[0]] - 1) // 2,
                  (arr[mn[1]] - arr[mn[0]-1] - 1) // 2,
                  (arr[mn[1]+1] - arr[mn[0]] - 1) // 2)
    print(ans)


def main():
    t = int(input())
    for _ in range(t):
        run()


if __name__ == "__main__":
    try:
        with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
            sys.stdin = fin
            sys.stdout = fout
            main()
    except IOError:
        main()

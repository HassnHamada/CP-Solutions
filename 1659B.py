import sys


def run():
    n, k = map(int, input().split())
    arr = input()
    ans = [0] * n
    if k == 0:
        print(arr)
        print(*ans)
        return
    ck = 0
    if (arr[0] == '1' and k % 2 == 1) or (arr[0] == '0' and k % 2 == 0):
        ans[0] += 1
        ck += 1
    for i in range(1, n):
        if ck == k:
            break
        a = (int(arr[i - 1]) + ck - ans[i - 1]) % 2
        b = (int(arr[i]) + ck - ans[i]) % 2
        if a == b:
            continue
        ans[i] += 1
        ck += 1
    if ck != k:
        ans[-1] += k - ck
    arr = "".join(str((int(arr[i]) + k - ans[i]) % 2) for i in range(n))
    print(arr)
    print(*ans)


# with open("_input.txt", 'r') as fin, open("_output.txt", 'w') as fout:
#     sys.stdin = fin
#     sys.stdout = fout
t = int(input())
for _ in range(t):
    run()

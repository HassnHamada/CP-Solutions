import sys


def run():
    n = int(input())
    arr = list(map(int, input().split()))
    if arr[-1] < arr[-2]:
        print(-1)
    else:
        if arr[-1] >= 0:
            ans = list()
            for i in range(n-3, -1, -1):
                arr[i] = arr[i + 1] - arr[-1]
                ans.append((i+1, i+2, n))
            print(len(ans))
            for i in ans:
                print(*i)
        else:
            if sorted(arr) != arr:
                print(-1)
            else:
                print(0)


with open("_input.txt", 'r') as fin, open("_output.txt", 'w') as fout:
    sys.stdin = fin
    sys.stdout = fout
    t = int(input())
    for _ in range(t):
        run()

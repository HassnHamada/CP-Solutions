import sys


def run():
    n = int(input())
    arr = list(map(int, input().split()))
    if all(arr[i] == 1 for i in range(1, n - 1)) or (n == 3 and arr[1] % 2 == 1):
        print(-1)
    else:
        ans = odds = 0
        for i in range(1, n - 1):
            ans += arr[i] // 2
            if arr[i] % 2:
                odds += 1
        print(ans + odds)


def main():
    t = int(input())
    for _ in range(t):
        run()


if __name__ == "__main__":
    # with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
    #     sys.stdin = fin
    #     sys.stdout = fout
    #     main()
    main()

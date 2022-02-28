import sys


def run():
    n = int(input())
    arr = list(map(int, input().split()))
    # print("in ", arr)
    for i in range(n):
        if arr[i] == i + 1:
            continue
        j = arr.index(i + 1)
        # print(i, j)
        # print(arr[j:i - 1:-1])
        arr[i:j + 1] = arr[i:j + 1][::-1]
        break
    print(*arr)
    #     return


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

import sys


def my_sum(arr, n, i, j):
    for k in range(n):
        if j >= k >= i:
            arr[k] ^= 1
    ret = sum(arr)
    for k in range(n):
        if j >= k >= i:
            arr[k] ^= 1
    return ret

def run():
    n = int(input())
    arr = list(map(int, input().split()))
    print(max(my_sum(arr, n, i, j) for i in range(n) for j in range(i, n)))


def main():
    # t = int(input())
    # for _ in range(t):
    #     run()
    run()


if __name__ == "__main__":
    # with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
    #     sys.stdin = fin
    #     sys.stdout = fout
    #     main()
    main()

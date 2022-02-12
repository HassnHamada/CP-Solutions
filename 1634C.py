# import sys


def run():
    n, k = map(int, input().split())
    if k == 1 or n % 2 == 0:
        print("YES")
        for i in range(n):
            print(*(i + j * n + 1 for j in range(k)))
    else:
        print("NO")


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

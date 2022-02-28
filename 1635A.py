import sys
from functools import reduce


def run():
    _ = int(input())
    print(reduce(int.__or__, map(int, input().split())))


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

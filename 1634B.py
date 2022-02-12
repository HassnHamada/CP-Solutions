# from functools import lru_cache
# import sys


def run():
    _, x, y = map(lambda x: int(x) % 2, input().split())
    arr = map(lambda x: int(x) % 2, input().split())
    print("Alice" if sum(arr) % 2 == x ^ y else "Bob")


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

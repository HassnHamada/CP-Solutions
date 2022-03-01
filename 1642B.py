import sys
from collections import Counter


def run():
    n = int(input())
    m = len(Counter(map(int, input().split())).keys())
    print(*(max(i+1, m) for i in range(n)))


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

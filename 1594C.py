# import sys


def main() -> None:
    # inF = open(".\\_input.txt", "r")
    # outF = open(".\\_output.txt", "w")
    # sys.stdout = outF
    # sys.stdin = inF
    t: int = int(input())
    for i in range(t):
        run()
    # inF.close()
    # outF.close()


def run() -> None:
    n, c = input().split()
    n = int(n)
    s = input()
    if all(s[i] == c for i in range(n)):
        print(0)
        return
    for i in range(2, n + 1):
        if all(s[j] == c for j in range(i - 1, n, i)):
            print(1)
            print(i)
            return
    print(2)
    print(n - 1, n)


if __name__ == "__main__":
    main()
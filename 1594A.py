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
    n: int = int(input())
    print(1 - n, n)


if __name__ == "__main__":
    main()
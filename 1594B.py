# import sys

MOD: int = int(1e9 + 7)


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
    n, k = map(int, input().split())
    print(sum(pow(n, i, MOD) if (1 << i) & k else 0 for i in range(32)) % MOD)


if __name__ == "__main__":
    main()
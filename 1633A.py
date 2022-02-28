import sys


def run():
    n = int(input())
    print(n // 7 * 7 if n // 7 * 7 // 10 == n // 10 else (n // 7 + 1) * 7)


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
    except:
        main()

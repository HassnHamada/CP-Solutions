import sys


def run():
    l, r, a = map(int, input().split())
    v = (r + 1) // a * a - 1 if (r + 1) // a * a - 1 >= l else r
    print(v // a + v % a)


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

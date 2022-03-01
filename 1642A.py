import sys


def run():
    ans = 0
    x = y = -1
    for _ in range(3):
        a, b = map(int, input().split())
        if b > y:
            y = b
            x = a
            ans = 0
        elif b == y:
            ans = abs(x - a)
    print(ans)


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

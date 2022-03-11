import sys


def run():
    s, c = input(), input()
    ok, i = False, -1
    while not ok:
        try:
            i = s.index(c, i + 1)
            ok = i % 2 == (len(s) - i - 1) % 2 == 0
        except:
            break
    print("YES" if ok else "NO")


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

import sys


def run():
    s = input()
    print("YES" if all(s.index(i) > s.index(j)
          for i, j in zip("RGB", "rgb")) else "NO")


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

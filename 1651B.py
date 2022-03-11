import sys


def run():
    n = int(input())
    ans = list()
    i = 1
    while len(ans) < n and i <= 1e9:
        ans.append(i)
        i *= 3
    if len(ans) == n:
        print("YES")
        print(*ans)
    else:
        print("NO")


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

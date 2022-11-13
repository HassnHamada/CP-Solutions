import sys


def main():
    t = int(input())
    for _ in range(t):
        a, b, c = map(int, input().split())
        print("YES" if a + b == c or a + c == b or b + c == a else "NO")


if __name__ == "__main__":
    try:
        with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
            sys.stdin = fin
            sys.stdout = fout
            main()
    except:
        main()

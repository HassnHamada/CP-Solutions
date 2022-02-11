import sys

def main():
    _, l = map(int, input().split())
    ans, o = 0, None
    # print(sorted(set(map(int, input().split())) | {0, l}))
    for n in sorted(set(map(int, input().split()))):
        ans = max(ans, 2 * n if o is None else n - o)
        o = n
    ans = max(ans, 2 * (l - n))
    print(ans / 2)

if __name__ == "__main__":
    try:
        with open("_input.txt", "r") as inf, open("_output.txt", "w") as outf:
            sys.stdin = inf
            sys.stdout = outf
            main()
    except:
        main()
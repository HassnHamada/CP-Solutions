import sys


def run():
    _ = int(input())
    arr = list(map(int, input().split()))
    o = e = 0
    ok = True
    for v in arr:
        if v & 1:
            ok &= o <= v
            o = v
        else:
            ok &= e <= v
            e = v
    print("YES" if ok else "NO")


def main():
    t = int(input())
    for _ in range(t):
        run()


if __name__ == "__main__":
    # with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
    #     sys.stdin = fin
    #     sys.stdout = fout
    #     main()
    main()

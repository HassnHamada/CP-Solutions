import sys


def run():
    n = int(input())
    # print(n)
    l = list(map(int, input().split()))
    l.reverse()
    # print(l)
    o = None
    d = False
    for i, v in enumerate(l):
        # print(i, v, o, d)
        if o is not None:
            if d:
                if v <= o:
                    pass
                else:
                    print(n - i)
                    return
            else:
                if v >= o:
                    pass
                else:
                    d = True
        o = v
    print(0)


def main():
    for _ in range(int(input())):
        run()


if __name__ == "__main__":
    try:
        with open("_input.txt", "r") as inf, open("_output.txt", "w") as outf:
            sys.stdin = inf
            sys.stdout = outf
            main()
    except:
        main()
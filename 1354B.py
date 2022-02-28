import sys


def run():
    sss = input()
    ans = float("inf")
    a = b = c = -1
    for i, v in enumerate(sss):
        if v == '1':
            a = i
        if v == '2':
            b = i
        if v == '3':
            c = i
        if -1 not in {a, b, c}:
            ans = min(ans, max(a, b, c) - min(a, b, c) + 1)
    print(ans if ans != float("inf") else 0)


def main():
    t = int(input())
    for _ in range(t):
        run()
    # run()


if __name__ == "__main__":
    # with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
    #     sys.stdin = fin
    #     sys.stdout = fout
    #     main()
    main()

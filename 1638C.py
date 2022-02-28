
import sys


def run():
    _ = int(input())
    arr = list(map(int, input().split()))
    ans = list()
    for v in arr:
        w = v
        while len(ans) and ans[-1] > v:
            w = max(w, ans.pop())
        ans.append(w)
    print(len(ans))


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

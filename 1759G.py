import sys


def main():
    n = int(input())
    inp = sorted(((v-1, i) for i, v in enumerate(map(int, input().split()))),
                 reverse=True)
    usd = [False] * n
    ans = [None] * n

    def ok():
        for i in range(n):
            if usd[i]:
                continue
            assert len(inp) > 0
            if i >= inp[-1][0] or usd[inp[-1][0]]:
                return False
            usd[i] = usd[inp[-1][0]] = True
            ans[inp[-1][1]*2] = i + 1
            ans[inp[-1][1]*2+1] = inp[-1][0] + 1
            inp.pop()
        return True

    if ok():
        print(*ans)
    else:
        print(-1)


stdout = sys.stdout
stdin = sys.stdin

try:
    with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
        sys.stdin = fin
        sys.stdout = fout
        t = int(input())
        for _ in range(t):
            main()
except FileNotFoundError:
    t = int(input())
    for _ in range(t):
        main()

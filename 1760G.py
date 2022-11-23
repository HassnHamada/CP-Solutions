import sys


def main():
    n, a, b = map(int,  input().split())
    tre = list(list() for _ in range(n+1))
    for _ in range(n-1):
        u, v, w = map(int, input().split())
        tre[u].append((v, w))
        tre[v].append((u, w))

    def dfs(n, p=0, c=0, *, b=None, out: dict = None) -> None:
        if b is not None and n == b:
            return
        assert n not in out
        out[n] = c
        for v, w in tre[n]:
            if v == p:
                continue
            dfs(v, n, c ^ w, b=b, out=out)

    s_a, s_b = dict(), dict()
    dfs(a, b=b, out=s_a), dfs(b, out=s_b)
    assert b not in s_a
    del s_b[b]
    s_a, s_b = set(s_a.values()), set(s_b.values())
    print("YES" if len(s_a & s_b) else "NO")


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

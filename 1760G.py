import sys


def main():
    n, a, b = map(int,  input().split())
    tre = list(list() for _ in range(n+1))
    for _ in range(n-1):
        u, v, w = map(int, input().split())
        tre[u].append((v, w))
        tre[v].append((u, w))

    def dfs(n, p=0, c=0, *, b=None, out: dict = None) -> None:
        stk = [(n, p, c, ((i, j) for i, j in tre[n]))]
        while len(stk) != 0:
            n, p, c, gen = stk[-1]
            if b is not None and n == b:
                stk.pop()
                continue
            if n not in out:
                out[n] = c
            else:
                assert out[n] == c
            try:
                v, w = next(gen)
                while v == p:
                    v, w = next(gen)
            except StopIteration:
                stk.pop()
                continue
            stk.append((v, n, c ^ w, ((i, j) for i, j in tre[v])))

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

from collections import Counter
import sys


def run():
    n = int(input())
    tre: dict[int, list] = dict()
    for i in range(n - 1):
        u, v = map(int, input().split())
        if u not in tre:
            tre[u] = list()
        if v not in tre:
            tre[v] = list()
        tre[u].append((v, i))
        tre[v].append((u, i))

    ok, s = True, 0
    for k, v in tre.items():
        if len(v) > 2:
            ok = False
        if len(v) == 1:
            s = k
    if ok:
        ans = [0] * (n - 1)
        p = (-1, 5)
        while True:
            for v in tre[s]:
                if v[0] == p[0]:
                    continue
                p = (s, 2 if p[1] == 5 else 5)
                s = v[0]
                ans[v[1]] = p[1]
                break
            if len(tre[s]) == 1:
                break
        print(*ans)
    else:
        print(-1)


# with open("_input.txt", 'r') as fin, open("_output.txt", 'w') as fout:
#     sys.stdin = fin
#     sys.stdout = fout
t = int(input())
for _ in range(t):
    run()


import sys


def main():
    n = int(input())
    inp = list(input() for _ in range(n))
    grf = dict((i, list()) for i in range(n))
    for i, v in enumerate(inp):
        for j, u in enumerate(v):
            if u == '1':
                grf[j].append(i)

    ans = list(set() for _ in range(n))
    num, vis = 0, [False] * n

    def dfs(n):
        vis[n] = True
        for i in grf[n]:
            if not vis[i]:
                dfs(i)
            ans[n] |= ans[i]
        nonlocal num
        ans[n].add(num := num + 1)

    for i in range(n):
        if not vis[i]:
            dfs(i)
        assert num <= n
        print(len(ans[i]), *ans[i])


# stdout = sys.stdout
# stdin = sys.stdin

# with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
#     sys.stdin = fin
#     sys.stdout = fout
#     t = int(input())
#     for _ in range(t):
#         main()

t = int(input())
for _ in range(t):
    main()

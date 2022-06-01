n, x = map(int, input().split())
ans = 100


def dfs(x, c=0):
    global ans
    if c + n - len(str(x)) >= ans:
        return
    if len(str(x)) == n:
        ans = c
        return
    for i in sorted(map(int, set(str(x))), reverse=True):
        if i <= 1:
            continue
        dfs(x * i,  c + 1)


dfs(x)
print(ans if ans != 100 else -1)

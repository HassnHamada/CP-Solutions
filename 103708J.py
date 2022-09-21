# from functools import lru_cache
# import sys


# sys.stdin = open("_input.txt", 'r')
# sys.stdout = open("_output.txt", 'w')

# N = int(5e4)

n, m = map(int, input().split())
grf: dict[int, list] = dict((i, list()) for i in range(m))
for i in range(n):
    gen = map(int, input().split())
    next(gen)
    for j in gen:
        grf[j - 1].append(i)

# print(grf)

nxtn, nxtm = [-1] * n, [-1] * m
vis = [0] * m
vid = ans = 0


def canCon(ii):
    if vis[ii] == vid:
        return False
    vis[ii] = vid
    for i in grf[ii]:
        if nxtn[i] == -1 or canCon(nxtn[i]):
            nxtn[i] = ii
            nxtm[ii] = i
            return True
    return False

for i in range(m):
    vid += 1
    if nxtm[i] == -1 and canCon(i):
        ans += 1

print(m - ans)
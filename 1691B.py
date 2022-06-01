t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    asd = dict()
    ans = [0]*n
    for i, v in enumerate(arr):
        if v not in asd:
            asd[v] = list()
        asd[v].append(i)
    for i in asd.keys():
        if len(asd[i]) == 1:
            ans = False
            break
        m = len(asd[i])
        for j in range(m):
            ans[asd[i][j]] = asd[i][(j+1)%m] + 1
    if ans is False:
        print(-1)
    else:
        print(*ans)

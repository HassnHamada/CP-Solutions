from heapq import heappop, heappush

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    arr = list(list() for _ in range(n))
    for _ in range(m):
        x, y = map(int, input().split())
        if x > y:
            x, y = y, x
        arr[x-1].append(y-1)
    for i in arr:
        i.sort(reverse=True)
    ans, j, hep = 0, 0, list()

    def add(v):
        if len(arr[v]):
            heappush(hep, (arr[v][-1], v))
            arr[v].pop()

    for i in range(n):
        add(i)
        while len(hep) and hep[0][0] == i:
            k = heappop(hep)[1]
            j = max(j, k + 1)
            add(k)
        ans += i - j + 1
    print(ans)

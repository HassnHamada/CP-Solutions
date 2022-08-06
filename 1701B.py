t = int(input())
for _ in range(t):
    n = int(input())
    ans = list()
    for i in range(1, n+1, 2):
        while i <= n:
            ans.append(i)
            i *= 2
    print(2)
    print(*ans)
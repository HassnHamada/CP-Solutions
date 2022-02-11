t = int(input())
for _ in range(t):
    n = int(input())
    k = list(map(int, input().split()))
    h = list(map(int, input().split()))
    for i in range(n - 2, -1, -1):
        h[i] = max(h[i], h[i + 1] - k[i + 1] + k[i])
    ans = 0
    for i in range(n):
        if i == 0 or k[i] - h[i] >= k[i - 1]:
            ans += h[i] * (h[i] + 1) // 2
        else:
            ans += (k[i] - k[i - 1]) * h[i - 1]
            ans += (k[i] - k[i - 1]) * (k[i] - k[i - 1] + 1) // 2
            h[i] = h[i - 1] + k[i] - k[i - 1]
    print(ans)

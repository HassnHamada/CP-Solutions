while True:
    n, m, p = map(int, input().split())
    if n == m == p == 0:
        break
    n -= 7
    m -= 7
    print(n // 2 * m + (n & 1) * (m + p) // 2)

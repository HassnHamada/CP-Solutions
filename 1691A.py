t = int(input())
for _ in range(t):
    n = int(input())
    arr = map(int, input().split())
    odd = sum(i % 2 for i in arr)
    print(min(n - odd, odd))

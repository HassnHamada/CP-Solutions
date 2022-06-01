t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    tot = sum(arr)
    print("Yes" if all(arr[0] == i for i in arr) or
          any((tot-arr[i]) == (n-1) * arr[i] for i in range(n)) else "No")

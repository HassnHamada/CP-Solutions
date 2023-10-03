from functools import reduce

t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    mn = min(arr)
    arr[arr.index(mn)] += 1
    print(reduce(int.__mul__, arr, 1))

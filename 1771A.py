from collections import Counter

t = int(input())
for _ in range(t):
    n = int(input())
    arr = sorted(map(int, input().split()))
    cnt = Counter(arr)
    if arr[0] == arr[-1]:
        print(n * (n - 1))
    else:
        print(cnt[arr[0]] * cnt[arr[-1]] << 1)

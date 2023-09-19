from itertools import permutations, combinations

n = int(input())
arr = sorted(map(int, input().split()))


def is_prime(n):
    if n == 1:
        return False
    for i in range(2, n+1):
        if i * i > n:
            return True
        if n % i == 0:
            return False
    assert False

ans = set()

for i, j in permutations(arr, 2):
    # print(i, j)
    if is_prime(i):
        ans.add((i, j))

ans_2 = set()
print(ans)
for i in combinations(ans, n):
    tem = list()
    for j in i:
        tem.extend(j)
    tem.sort()
    if tem == arr:
        num = 1
        print(i)
        for j, k in i:
            num *= j**k
        ans_2.add(num)
print(ans_2)
# 2**1 * 3**2
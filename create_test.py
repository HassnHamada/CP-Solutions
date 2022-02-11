import sys
from random import randint
from collections import Counter

sys.stdout = open(r"C:\.code\_input.txt", 'w')
N, M = int(1e5), int(1e5)
print(N)
nums = list(randint(1, M) for _ in range(N))
print(*nums)
counter = Counter(nums)
max_count = max(counter.values())
print(max_count, end=" ")
print(*(key for key, val in zip(counter.keys(), counter.values())
        if val == max_count))
sys.stdout.close()
from numpy import base_repr

n, b = int(input()), int(input())
print(base_repr(sum(int(input(), b) for _ in range(n)), b))

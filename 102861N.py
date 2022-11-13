from functools import reduce
from math import lcm
import sys

N = 4 * 10**7


def main():
    _, _, _ = map(int, input().split())
    v = reduce(lcm,  map(int, input().split()))

    def sieve(n):
        yield 2
        prime = [True] * (n // 2)
        for i in range(3, n, 2):
            if not prime[i // 2]:
                continue
            yield i
            for j in range(i * i, n, 2*i):
                prime[j // 2] = False

    ans = list()
    for i in sieve(N):
        if v % i == 0:
            ans.append(i)
            while v % i == 0:
                v //= i
        if v == 1:
            break
    assert v == 1
    print(*ans)


if __name__ == "__main__":
    try:
        with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
            sys.stdin = fin
            sys.stdout = fout
            main()
    except:
        main()

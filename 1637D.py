from functools import lru_cache
import sys


# def calc(arr, i, n):
#     ret = 0
#     for j in range(n):
#         if i == j:
#             continue
#         ret += (arr[i] + arr[j])**2
#     return ret


# 3*a^2 + 3*b^2 + 3*c^2 + 3*d^2 + 2*a*(b+c+d) + 2*b*(c+d) + 2*c*(d)

def calcTot(bs):
    ret = (n - 1) * sum(i**2 + j**2 for i, j in zip(aaa, bbb))
    tot_a = tot_b = 0
    for i in range(n):
        tot_a += [aaa, bbb][(bs >> i) & 1][i]
        tot_b += [bbb, aaa][(bs >> i) & 1][i]
    for i in range(n):
        tot_a -= [aaa, bbb][(bs >> i) & 1][i]
        tot_b -= [bbb, aaa][(bs >> i) & 1][i]
        ret += 2 * [aaa, bbb][(bs >> i) & 1][i] * tot_a
        ret += 2 * [bbb, aaa][(bs >> i) & 1][i] * tot_b
    return ret


@lru_cache
def work(i, bs):
    if i == n:
        return calcTot(bs)
    return min(work(i + 1, bs), work(i + 1, bs | (1 << i)))


def run():
    global n, aaa, bbb
    n = int(input())
    aaa = list(map(int, input().split()))
    bbb = list(map(int, input().split()))
    print(work(0, 0))
    work.cache_clear()


def main():
    t = int(input())
    for _ in range(t):
        run()


if __name__ == "__main__":
    # with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
    #     sys.stdin = fin
    #     sys.stdout = fout
    #     main()
    main()

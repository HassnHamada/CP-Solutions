import sys

MOD = int(1e9+7)


def g_sum(a, r, n, m=MOD):
    return a * (pow(r, n, m) - 1 + m) * pow(r - 1, -1, m) % m


def main():
    n = int(input())
    num_ = 1
    inp = list()
    for _ in range(n):
        inp.append(tuple(map(int, input().split())))
        num_ = num_ * (inp[-1][1] + 1)
    sum_ = pro_ = 1
    for i, j in inp:
        sum_ = (sum_ + sum_ * g_sum(i, i, j) % MOD) % MOD
        pro_ = pro_ * pow(i, num_ * j // 2, MOD) % MOD
    print(num_ % MOD, sum_, pro_)


if __name__ == "__main__":
    with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
        sys.stdin = fin
        sys.stdout = fout
        main()
# main()


import sys


def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


def ex_gcd(a, b):
    _a, _b = list(), list()
    while b != 0:
        _a.append(a)
        _b.append(b)
        a, b = b, a % b
    x, y = 1, 0
    for i, j in zip(_a[::-1], _b[::-1]):
        x, y = y, x - y * (i // j)
    return (a, x, y)


def main():
    while True:
        o1, f1, o2, f2 = map(int, input().split())
        if o1 == f1 == o2 == f2 == 0:
            break
        o2 += f2
        assert f1 and f2
        # if f1 == f2 == 0:
        #     print(o1 if o1 == o2 else "Impossible")
        #     continue
        # if f1 == 0 or f2 == 0:
        #     if f2:
        #         f1, f2 = f2, f1
        #         o1, o2 = o2, o1
        #     assert(f2)
        #     print(o2 if o2 >= o1 and (o2 - o1) % f1 == 0 else "Impossible")
        #     continue
        g, x, y = ex_gcd(f1, f2)
        if (o2 - o1) % g:
            print("Impossible")
        else:
            f = f1 * f2 // g
            n1 = (x % f * (o2 - o1) // g % f + f) % f
            n2 = (y % f * (o1 - o2) // g % f + f) % f
            assert (n1 * f1 + o1 - o2) % f2 == 0
            assert (n2 * f2 + o2 - o1) % f1 == 0
            assert (n1 * f1 + o1) % f == (n2 * f2 + o2) % f
            ans = (n1 * f1 + o1) % f
            if ans < max(o1, o2):
                ans += (max(o1, o2) - ans + f - 1) // f * f
            assert ans >= max(o1, o2)
            assert ans - f < max(o1, o2)
            print(ans)


stdout = sys.stdout
stdin = sys.stdin

# with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
#     sys.stdin = fin
#     sys.stdout = fout
#     main()
main()

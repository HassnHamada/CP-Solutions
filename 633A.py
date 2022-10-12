
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
    def solve(a, b, c) -> bool:
        g, x, y = ex_gcd(a, b)
        if c % g:
            return False
        x *= c // g
        y *= c // g
        assert a * x + b * y == c
        if x < 0 or y < 0:
            if y < 0:
                x, y = y, x
                a, b = b, a
            k = (abs(x) + b // g - 1) // (b // g)
            x += k * b // g
            y -= k * a // g
            assert a * x + b * y == c
        return x >= 0 and y >= 0
    print("Yes" if solve(*map(int, input().split())) else "No")


stdout = sys.stdout
stdin = sys.stdin

# with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
#     sys.stdin = fin
#     sys.stdout = fout
#     main()
main()

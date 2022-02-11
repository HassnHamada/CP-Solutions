import sys
# from functools import lru_cache


def get_min(m, s):
    r = 0
    while s != 0:
        r *= 10
        if (m - 1) * 9 <= s:
            r += s - (m - 1) * 9
            s = (m - 1) * 9
        elif r == 0:
            r = 1
            s -= 1
        m -= 1
    while m != 0:
        r *= 10
        m -= 1
    assert m == 0 and s == 0
    return r


def get_max(m, s):
    r = 0
    while s != 0:
        r *= 10
        r += min(9, s)
        s -= min(9, s)
        m -= 1
    while m != 0:
        r *= 10
        m -= 1
    assert m == 0 and s == 0
    return r


def main():
    m, s = map(int, input().split())
    if (s == 0 and m > 1) or m * 9 < s:
        print(-1, -1)
    else:
        print(get_min(m, s), get_max(m, s))


if __name__ == "__main__":
    try:
        with open("_input.txt", "r") as inf, open("_output.txt", "w") as outf:
            sys.stdin = inf
            sys.stdout = outf
            main()
    except:
        main()
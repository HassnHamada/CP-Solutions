import sys


def run():
    n, d12, d23, d13 = map(int, input().split())
    s = d12 + d23 + d13
    x = -d12 + d13 + d23
    y = d12 - d13 + d23
    z = d12 + d13 - d23
    r = 4
    if s % 2 == 1:
        r = -1
    elif d23 == d12 + d13:
        r = 1
    elif d13 == d12 + d23:
        r = 2
    elif d12 == d23 + d13:
        r = 3
    elif x % 2 == 1 or y % 2 == 1 or z % 2 == 1 or min(x//2, y//2, z//2) <= 0 or x//2 + y//2 + z//2 > n - 1 or n == 3:
        r = -1
    if r == -1:
        print("No")
    else:
        edg = list()
        for i, v in enumerate([[0, d12, d13],
                               [d12, 0, d23],
                               [d13, d23, 0],
                               [z//2, y//2, x//2]][r - 1]):
            if i + 1 == r:
                continue
            c = r
            for _ in range(v - 1):
                edg.append((c, n))
                c = n
                n -= 1
            edg.append((c, i + 1))
        while n > max(3, r):
            edg.append((r, n))
            n -= 1
        print("Yes")
        for i in edg:
            print(*i)


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

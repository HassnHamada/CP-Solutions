import sys


def main():
    n, c, d = map(int,  input().split())
    arr = sorted(map(int,  input().split()), reverse=True)
    if arr[0] * d < c:
        print("Impossible")
    elif sum(arr[:min(d, n)]) >= c:
        print("Infinity")
    else:
        l, h = 0, 1 << 20
        while h:
            m = (h >> 1) + l
            if m <= d:
                if sum(arr[:d % m]) + d // m * sum(arr[:min(n, m)]) >= c:
                    l = m
            h >>= 1
        print(l-1)


stdout = sys.stdout
stdin = sys.stdin

try:
    with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
        sys.stdin = fin
        sys.stdout = fout
        t = int(input())
        for _ in range(t):
            main()
except FileNotFoundError:
    t = int(input())
    for _ in range(t):
        main()

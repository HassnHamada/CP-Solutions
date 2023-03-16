import sys


def main():
    t = int(input())
    for _ in range(t):
        n, x, p = map(int, input().split())
        my_set = set((i * (i + 1) // 2 + x) % n for i in range(1, min(2*n, p+1)))
        # (i * (i + 1) // 2 + x) % n

        # (2n * (2n + 1) // 2 + x) % n
        # (2n^2 + n + x) % n
        # 2n^2 % n + n % n + x % n
        # 0 + 0 + x % n
        # x % n

        # (i + 2n) * (i + 2n + 1) // 2 + x) % n
        # (i^2 + 4ni + 4n^2 + 2n + i) // 2 + x) % n
        # ((i + 2n)^2 + 2n + i) // 2 + x) % n
        print('YES' if 0 in my_set else 'NO')


if __name__ == "__main__":
    with open("_input.txt", "r") as inf, open("_output.txt", "w") as outf:
        sys.stdin = inf
        sys.stdout = outf
        main()

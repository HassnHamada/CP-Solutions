import sys


def main():
    t = int(input())
    for _ in range(t):
        n, p, i = map(float, input().split())
        # sum (1 - p)**(n*i) for i from 0 to inf
        try:
            print(f"{(1 - p)**(i - 1) * p / (1 - (1 - p)**n):.4f}")
        except ZeroDivisionError:
            print("0.0000")


with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
    sys.stdin = fin
    sys.stdout = fout
    main()

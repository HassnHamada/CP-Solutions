import sys


def main():
    _ = int(input())
    arr = list(map(int,  input().split()))
    mx = [(0, -1)] * 3
    for i, v in enumerate(arr):
        mx[2] = (v, i)
        mx.sort(reverse=True)
    print(*(v - mx[1 if i == mx[0][1] else 0][0] for i, v in enumerate(arr)))


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

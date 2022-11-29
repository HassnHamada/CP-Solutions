import sys


def main():
    n = int(input())
    arr = list(map(int,  input().split()))
    one = list()
    for i, v in enumerate(arr):
        one.append(v + (one[-1] if i else 0))
    inv = 0
    for i, v in enumerate(arr):
        if v == 0:
            inv += one[i]
    tem_1 = tem_2 = -1
    try:
        z = arr.index(0)
        # was 11111 0 01010100101
        tem_1 = inv + n - z - one[-1] - 1
    except ValueError:
        pass
    try:
        o = n - arr[::-1].index(1) - 1
        # was 10010100100 1 00000
        assert one[-1] == one[o]
        tem_2 = inv - n + o + one[o]
    except ValueError:
        pass
    print(max(inv, tem_1, tem_2))


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

import sys


def run():
    input()
    n, m = map(int, input().split())
    arr = list((i+1, *map(int, input().split())) for i in range(m))
    arr.sort(key=lambda v: v[2])
    while len(arr) > 2 * n:
        arr.pop()
    arr.sort(key=lambda v: v[1])
    print(sum(i[2] for i in arr))
    for i in range(n):
        print(arr[i][0], arr[-i-1][0])
    assert False
    print()


def main():
    t = int(input())
    for _ in range(t):
        run()


if __name__ == "__main__":
    try:
        with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
            sys.stdin = fin
            sys.stdout = fout
            main()
    except IOError:
        main()

import sys
from collections import Counter


def run():
    ans = 0
    _, x = map(int, input().split())
    arr = sorted(map(int, input().split()), reverse=True)
    counter = Counter(arr)
    while len(arr) != 0:
        v = arr.pop()
        if v not in counter:
            continue
        counter[v] -= 1
        if counter[v] == 0:
            del counter[v]
        if v * x in counter:
            counter[v*x] -= 1
            if counter[v*x] == 0:
                del counter[v*x]
        else:
            ans += 1
    print(ans)


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

import sys
from itertools import permutations


def run():
    n = int(input())
    ans = list()
    for i in permutations(range(n, 0, -1)):
        if any(i[j-2]+i[j-1] == i[j] for j in range(2, n)):
            continue
        ans.append(i)
        if len(ans) == n:
            break
    for i in ans:
        print(*i)


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

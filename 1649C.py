import sys


def run():
    n, _ = map(int, input().split())
    aaa, bbb = dict(), dict()
    for i in range(n):
        for j, c in enumerate(map(int, input().split())):
            if c not in aaa:
                aaa[c] = list()
                bbb[c] = list()
            aaa[c].append(i)
            bbb[c].append(j)
    for i, j in zip(aaa.values(), bbb.values()):
        i.sort()
        j.sort()
    ans = 0
    for i in aaa.values():
        for j in range(1, len(i)):
            ans += (i[j] - i[j - 1]) * j * (len(i) - j)
    for i in bbb.values():
        for j in range(1, len(i)):
            ans += (i[j] - i[j - 1]) * j * (len(i) - j)
    print(ans)


def main():
    t = 1
    # t = int(input())
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

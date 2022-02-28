import sys
from collections import Counter


def red(i, bbb):
    if i in bbb:
        bbb[i] -= 1
        if bbb[i] == 0:
            del bbb[i]
        return True
    return False


def main():
    _ = input()
    aaa = list(map(int, input().split()))
    _ = input()
    aaa.sort()
    bbb = Counter(map(int, input().split()))
    ans = 0
    for i in aaa:
        if red(i - 1, bbb) or red(i, bbb) or red(i + 1, bbb):
            ans += 1
    print(ans)

if __name__ == "__main__":
    try:
        with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
            sys.stdin = fin
            sys.stdout = fout
            main()
    except:
        main()

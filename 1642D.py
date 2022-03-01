import sys
from collections import Counter


def run():
    n = int(input())
    arr = list(map(int, input().split()))
    counter = Counter(arr)
    if any(i % 2 == 1 for i in counter.values()):
        print(-1)
    else:
        ext, stk, ans = list(), list(), list()
        for i in range(n):
            if len(stk) != 0 and stk[-1] == arr[i]:
                ext.append(stk.pop())
            else:
                ans.append((n + len(ext), arr[i]))
                ext.append(arr[i])
                stk.append(arr[i])
            print(ext)
            print(stk)
        assert len(stk) % 2 == 0
        assert all(stk[i] == stk[len(stk)//2+i] for i in range(len(stk) // 2))
        assert len(ext) + len(stk) == 2 * len(ans)
        print(len(ans))
        print(*(f"{i} {j}"for i, j in ans), sep='\n')
        if len(stk) == 0:
            print(1)
            print(n + len(ext))
        else:
            print(2)
            print(n + len(ext), len(stk))


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

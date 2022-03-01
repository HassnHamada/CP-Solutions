import sys
from collections import Counter


def magic(arr, n, ans_q: list, ex):
    stk = list()
    for i in range(1, n):
        if len(stk) != 0 and stk[-1] == arr[i]:
            stk.pop()
        else:
            ans_q.append((ex + n + i, arr[i]))
            stk.append(arr[i])
    return stk[::-1] + arr[n+1:]


def run():
    _ = int(input())
    arr = list(map(int, input().split()))
    counter = Counter(arr)
    if any(i % 2 == 1 for i in counter.values()):
        print(-1)
    else:
        ex = 0
        ans_q, ans_l = list(), list()
        while len(arr) != 0:
            ans_l.append(arr.index(arr[0], 1))
            arr = magic(arr, ans_l[-1], ans_q, ex)
            ex += 2 * ans_l[-1]
        print(len(ans_q))
        if len(ans_q) != 0:
            print(*(f"{i} {j}" for i, j in ans_q), sep='\n')
        print(len(ans_l))
        print(*(2*i for i in ans_l))


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

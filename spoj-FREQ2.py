from bisect import bisect_left
from collections import Counter
import sys


N, Q = 2e5 + 10, 448

arr = list()


class Query:
    def __init__(self, l, r, i) -> None:
        self.l = l
        self.r = r
        self.i = i

    def val(self):
        return self.l // Q * N + self.r

    def __lt__(self, other) -> int:
        return self.val() < other.val()

    def __str__(self) -> str:
        return f"[{self.l}, {self.r}]"


counter = Counter()


def add(val):
    counter[val] += 1


def rem(val):
    counter[val] -= 1


s = e = 0


def updateSE(qs, qe):
    global s, e
    while e < qe + 1:
        add(arr[e])
        e += 1

    while s > qs:
        s -= 1
        add(arr[s])

    while s < qs:
        rem(arr[s])
        s += 1

    while e > qe + 1:
        e -= 1
        rem(arr[e])


def main():
    n, q = map(int, input().split())
    arr.extend(map(int, input().split()))
    srt = sorted(arr)
    m = 1
    for v in srt:
        if v == srt[m - 1]:
            continue
        srt[m] = v
        m += 1
    while len(srt) > m:
        srt.pop()
    for i, v in enumerate(arr):
        arr[i] = bisect_left(srt, v)
    qqq: list[Query] = list()
    for i in range(q):
        qqq.append(Query(*map(int, input().split()), i))
    ans = [0] * q
    for i in qqq:
        updateSE(i.l, i.r)
        ans[i.i] = counter.most_common(1)[0][1]
    print(*ans, sep="\n")


if __name__ == "__main__":
    # with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
    #     sys.stdin = fin
    #     sys.stdout = fout
    #     main()
    main()

import sys
from functools import lru_cache


class mySet(set):
    def __init__(self, __iterable):
        super().__init__(__iterable)

    def __hash__(self):
        return hash(self.__str__())

    def __sub__(self, __s):
        return mySet(super().__sub__(__s))


def run():
    n = int(input())
    aaa = list(map(int, input().split()))
    bbb = list(map(int, input().split()))
    i = (0, min((i for i in range(n)), key=lambda x: abs(bbb[x]-aaa[0])))
    j = (n-1, min((i for i in range(n)), key=lambda x: abs(bbb[x]-aaa[-1])))
    k = (min((i for i in range(n)), key=lambda x: abs(aaa[x]-bbb[0])), 0)
    l = (min((i for i in range(n)), key=lambda x: abs(aaa[x]-bbb[-1])), n-1)
    ii, jj, kk, ll = (0, 0), (0, n-1), (n-1, 0), (n-1, n-1)
    ans = [abs(aaa[0] - bbb[0]) + abs(aaa[-1] - bbb[-1])]

    @lru_cache
    def asd(sss, cur=0, t=0):
        if cur >= ans[0]:
            return
        if t == (1 << 4) - 1:
            ans[0] = cur
            return
        da = {0: 1, n-1: 2}
        db = {0: 4, n-1: 8}
        for i in sss:
            if (db.get(i[0], 0) & t) and (db.get(i[1], 0) & t):
                continue
            asd(sss - {i}, cur+abs(aaa[i[0]]-bbb[i[1]]),
                t | da.get(i[0], 0) | db.get(i[1], 0))
    asd(mySet([i, j, k, l, ii, jj, kk, ll]))
    print(ans[0])


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

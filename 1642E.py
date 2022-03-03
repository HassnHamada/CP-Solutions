from math import log, ceil
import sys


class SegmentTree():
    def __init__(self, size) -> None:
        self.size = 2**ceil(log(size, 2))
        # print(self.size)
        # self.tree = [1] * (2**(ceil(log(size, 2))+1)-1)
        self.tree = [1] * (2*self.size-1)
        # self.tree = [1] * (2**ceil(log(size, 2)+1))
        # self.tree = [1] * (2**(ceil(log(size, 2))+1))
        # self.tree = [1] * (4*self.size)

    def _set_no_sick(self, l, r, i, s, e):
        if r < s or l > e or (self.tree[i] & 1) == 0:
            return
        if s == e:
            # print(l, r, i, s, e)
            self.tree[i] = 2
            return
        ll, rr, m = 2*i+1, 2*i+2, (e+s)//2
        self._set_no_sick(l, r, ll, s, m)
        self._set_no_sick(l, r, rr, m+1, e)
        self.tree[i] = self.tree[ll] | self.tree[rr]

    def set_no_sick(self, l, r):
        return self._set_no_sick(l, r, 0, 0, self.size - 1)

    def _set_sick(self, l, r, i, s, e):
        # print(l, r, i, s, e)
        # assert (self.tree[i] & 1) != 0
        if r < s or l > e or (self.tree[i] & 1) == 0:
            # if r < s or l > e:
            return
            # print("dasdas")
        if s == e:
            # assert self.tree[i] == 1
            # if self.tree[i] == 1:
            #     self.tree[i] = 4
            # print("dasdas")
            self.tree[i] = 4
            # assert self.tree[i] == 3
            return
            # return True
        ll, rr, m = 2*i+1, 2*i+2, (e+s)//2
        # if s >= l and m <= r and (self.tree[ll] & 5) != 0 and m+1 >= l and e <= r and (self.tree[rr] & 5) != 0:
        # return
        # return False
        # a = b = False
        # assert (self.tree[ll] & 1) != (self.tree[rr] & 1)
        # if (self.tree[ll] & 1) == 1:
        self._set_sick(l, r, ll, s, m)
        # if (self.tree[rr] & 1) == 1:
        # if self.tree[rr] == 3:
        self._set_sick(l, r, rr, m+1, e)
        # if a and b:
        #     return False
        # if a or b:
        #     if a:
        #         self.tree[ll] = 2
        #     else:
        #         self.tree[rr] = 2
        self.tree[i] = self.tree[ll] | self.tree[rr]
        # return a or b

    def set_sick(self, l, r):
        return self._set_sick(l, r, 0, 0, self.size - 1)

    def _get(self, t, i, s, e):
        if t < s or t > e:
            return
        if self.tree[i] in {1, 2, 4}:
            return self.tree[i]
            # assert t == s
            # print(self.tree[i])
        ll, rr, m = 2*i+1, 2*i+2, (e+s)//2
        return self._get(t, ll, s, m) or self._get(t, rr, m+1, e)

    def get(self, t):
        return self._get(t, 0, 0, self.size - 1)

    # def _count_on_sick(self, l, r, i, s, e):
    #     if r < s or l > e or (self.tree[i] & 2) == 0:
    #         return 0
    #     if s == e:
    #         return 1
    #     ll, rr, m = 2*i+1, 2*i+2, (e+s)//2
    #     return self._count_on_sick(l, r, ll, s, m) + self._count_on_sick(l, r, rr, m+1, e)

    # def _count_on_sick(self, l, r, i, s, e):
    #     if r < s or l > e or (self.tree[i] & 2) == 0:
    #         return 0
    #     if self.tree[i] == 2:
    #         return e - s + 1
    #     if s != e:
    #         ll, rr, m = 2*i+1, 2*i+2, (e+s)//2
    #         return self._count_on_sick(l, r, ll, s, m) + self._count_on_sick(l, r, rr, m+1, e)
    #     return 0

    # def count_on_sick(self, l, r):
    #     return self._count_on_sick(l, r, 0, 0, self.size - 1)

    def _count_NA(self, l, r, i, s, e):
        # print(l, r, i, s, e)
        if r < s or l > e or (self.tree[i] & 1) == 0:
            return 0
        if self.tree[i] == 1:
            return e - s + 1
        if s != e:
            ll, rr, m = 2*i+1, 2*i+2, (e+s)//2
            return self._count_NA(l, r, ll, s, m) + self._count_NA(l, r, rr, m+1, e)
        return 0

    def count_NA(self, l, r):
        return self._count_NA(l, r, 0, 0, self.size - 1)

    def __str__(self) -> str:
        # ans = {2: "NO", 4: "YES", 1: "N/A"}
        # print(self.tree)
        # print(self.tree[len(self.tree)-self.size:])
        return " ".join(ans[i] for i in self.tree[len(self.tree)//2:])
# class Fenwick_Tree():
#     def __init__(self, size) -> None:
#         self.size = size
#         self.tree = [0] * size

#     def add(self, ind, val):
#         while ind < self.size:
#             self.tree[ind] += val
#             ind += ind & -ind

#     def get(self, ind):
#         ret = 0
#         while ind > 0:
#             ret += self.tree[ind]
#             ind -= ind & -ind
#         return ret


def run():
    n, q = map(int, input().split())
    # tree = SegmentTree(2**19)
    tree = SegmentTree(n)
    later = list()
    global ans
    ans = {2: "NO", 4: "YES", 1: "N/A"}
    for _ in range(q):
        t, *p = map(int, input().split())
        if t == 0:
            if p[2] == 0:
                tree.set_no_sick(p[0]-1, p[1]-1)
            else:
                later.append(p)
        else:
            tem = list()
            for i in later:
                print(i, tree.count_NA(i[0]-1, i[1]-1))
                # if tree.count_on_sick(i[0]-1, i[1]-1) == i[1] - i[0]:
                if tree.count_NA(i[0]-1, i[1]-1) == 1:
                    tree.set_sick(i[0]-1, i[1]-1)
                else:
                    tem.append(i)
            later = tem
            # tree.get(p[0])
            print(ans[tree.get(p[0]-1)])
        # print(tree.tree)
        # print("--------------")
        # for i in range(n):
        #     for j in range(i, n):
        #         print(i, j, tree.count_on_sick(i, j))
        # print("--------------")
    # arr = list(map(int, input().split()))


def main():
    # t = int(input())
    # for _ in range(t):
    #     run()
    run()


if __name__ == "__main__":
    try:
        with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
            sys.stdin = fin
            sys.stdout = fout
            main()
    except IOError:
        main()

import sys
from collections import Counter


MOD = int(10**9+7)


def main():
    class Mat:
        def __init__(self, x: int = 0, y: int = 0, mat: "Mat" = None):
            if mat is None:
                assert x and y
                self.x = x
                self.y = y
                self.mat = [[0] * y for _ in range(x)]
            else:
                self.x = mat.x
                self.y = mat.y
                self.mat = [list(i) for i in mat.mat]

        def __mul__(self, other: "Mat") -> "Mat":
            assert self.y == other.x
            ret = Mat(self.x, other.y)
            for i in range(ret.x):
                for j in range(ret.y):
                    for k in range(self.y):
                        ret.mat[i][j] += self.mat[i][k] * other.mat[k][j]
                        ret.mat[i][j] %= MOD
            return ret

        def identity(self):
            assert self.x == self.y
            for i in range(self.x):
                for j in range(self.y):
                    self.mat[i][j] = 1 if i == j else 0

        def __pow__(self, p: int) -> "Mat":
            assert self.y == self.x
            bas = Mat(mat=self)
            ret = Mat(self.x, self.y)
            ret.identity()
            while p:
                if p & 1:
                    ret = ret * bas
                bas = bas * bas
                p //= 2
            return ret

    _, b, k, x = map(int, input().split())
    frq = Counter(map(int, input().split()))
    t = Mat(x, x)
    for i in range(x):
        for j, v in frq.items():
            t.mat[i][(i * 10 + j) % x] += v

    i = Mat(1, x)
    i.mat[0][0] = 1

    print((i*t**b).mat[0][k])


with open("_input.txt", "r") as fin, open("_ok.txt", "w") as fout:
    sys.stdin = fin
    sys.stdout = fout
    main()

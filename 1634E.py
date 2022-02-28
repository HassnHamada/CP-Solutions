from itertools import combinations
from collections import Counter
import sys

dp = dict()


def get(i, val):
    k = (i, val)
    if k not in dp:
        if i == -1:
            if val == 0:
                print("YES")
                dp[k] = True
            else:
                dp[k] = False
        else:
            for j in combinations(mat[i], sz[i] // 2):
                if get(i - 1, val - sum(j)):
                    j = Counter(j)
                    for l in mat[i]:
                        if l in j and j[l]:
                            j[l] -= 1
                            print("L", end="")
                        else:
                            print("R", end="")
                    print()
                    dp[k] = True
                    break
            if k not in dp:
                dp[k] = False
    return dp[k]


def main():
    global mat, sz, m
    m = int(input())
    sz, mat = list(), list()
    tot = 0
    for _ in range(m):
        sz.append(int(input()))
        mat.append(list(map(int, input().split())))
        tot += sum(mat[-1])
    if not get(m - 1, tot // 2):
        print("NO")


if __name__ == "__main__":
    # with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
    #     sys.stdin = fin
    #     sys.stdout = fout
    #     main()
    main()

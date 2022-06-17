from collections import Counter
import sys


def run():
    n, m = map(int, input().split())
    mat = list(list(input()) for _ in range(n))
    if mat[0][0] == '1':
        print(-1)
    else:
        ans = list()
        for i in range(n):
            for j in range(m):
                assert mat[i][j] == '0'
                if i != n - 1 and mat[i + 1][j] == '1':
                    mat[i + 1][j] = '0'
                    ans.append((i+1, j+1, i+2, j+1))
                if j != m - 1 and mat[i][j + 1] == '1':
                    mat[i][j + 1] = '0'
                    ans.append((i+1, j+1, i+1, j+2))
        print(len(ans))
        for i in ans[::-1]:
            print(*i)


# with open("_input.txt", 'r') as fin, open("_output.txt", 'w') as fout:
#     sys.stdin = fin
#     sys.stdout = fout
t = int(input())
for _ in range(t):
    run()

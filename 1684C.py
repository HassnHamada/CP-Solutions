import sys


def run():
    n, m, = map(int, input().split())
    mat = [list(map(int, input().split())) for _ in range(n)]
    bad = list()
    for i in range(n):
        arr = sorted(mat[i])
        for j in range(m):
            if arr[j] != mat[i][j]:
                bad.append(j)
        if len(bad):
            break
    if len(bad) == 0:
        print(1, 1)
        return
    if len(bad) > 2:
        print(-1)
        return
    assert len(bad) == 2
    for i in range(n):
        mat[i][bad[0]], mat[i][bad[1]] = mat[i][bad[1]], mat[i][bad[0]]
    for i in range(n):
        for j in range(1, m):
            if mat[i][j] < mat[i][j - 1]:
                print(-1)
                return
    print(bad[0] + 1, bad[1] + 1)


# with open("_input.txt", 'r') as fin, open("_output.txt", 'w') as fout:
#     sys.stdin = fin
#     sys.stdout = fout
t = int(input())
for _ in range(t):
    run()

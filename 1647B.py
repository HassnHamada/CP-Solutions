import sys


def run():
    n, m = map(int, input().split())
    mat = list(input() for _ in range(n))

    def ok():
        for i in range(n):
            for j in range(m):
                if mat[i][j] == '0':
                    continue
                if i < n - 1 and j < m - 1 and mat[i][j] == mat[i+1][j] == mat[i][j+1] and mat[i+1][j+1] == '0':
                    return False
                if i < n - 1 and j and mat[i][j] == mat[i+1][j] == mat[i][j-1] and mat[i+1][j-1] == '0':
                    return False
                if i and j and mat[i][j] == mat[i-1][j] == mat[i][j-1] and mat[i-1][j-1] == '0':
                    return False
                if i and j < m - 1 and mat[i][j] == mat[i-1][j] == mat[i][j+1] and mat[i-1][j+1] == '0':
                    return False
        return True
    print("YES" if ok() else "NO")


# with open("_input.txt", 'r') as fin, open("_output.txt", 'w') as fout:
#     sys.stdin = fin
#     sys.stdout = fout
t = int(input())
for _ in range(t):
    run()

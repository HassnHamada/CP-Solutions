from queue import Queue
import sys


def run():
    n, m = map(int, input().split())
    grid = list()
    for _ in range(n):
        grid.append(list(map(int, input().split())))

    def ok(i, j):
        s = {grid[i][j], grid[i][j+1], grid[i+1][j], grid[i+1][j+1]}
        return len(s) == 1 or (len(s) == 2 and 0 in s)

    def get_col(i, j):
        if grid[i][j]:
            return grid[i][j]
        if grid[i+1][j]:
            return grid[i+1][j]
        if grid[i][j+1]:
            return grid[i][j+1]
        if grid[i+1][j+1]:
            return grid[i+1][j+1]
        assert False

    q, ans = Queue(), list()
    for i in range(n - 1):
        for j in range(m - 1):
            if ok(i, j):
                q.put((i, j))
    while not q.empty():
        i, j = q.get()
        if grid[i][j] == grid[i][j+1] == grid[i+1][j] == grid[i+1][j+1] == 0:
            continue
        ans.append((i+1, j+1, get_col(i, j)))
        grid[i][j] = grid[i][j+1] = grid[i+1][j] = grid[i+1][j+1] = 0
        for ii in range(max(0, i-1), min(n-1, i+2)):
            for jj in range(max(0, j-1), min(m-1, j+2)):
                if ok(ii, jj):
                    q.put((ii, jj))
    if all(all(j == 0 for j in i) for i in grid):
        print(len(ans))
        while len(ans):
            print(*ans.pop())
    else:
        print(-1)


def main():
    t = 1
    for _ in range(t):
        run()


if __name__ == "__main__":
    with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
        sys.stdin = fin
        sys.stdout = fout
        main()
    # main()

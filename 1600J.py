# import sys


def main() -> None:
    # inF = open(".\\_input.txt", "r")
    # outF = open(".\\_output.txt", "w")
    # sys.stdout = outF
    # sys.stdin = inF
    # t: int = int(input())
    t: int = 1
    for _ in range(t):
        run()
    # inF.close()
    # outF.close()


grid = list()
n, m = 0, 0


def run() -> None:
    global n, m
    n, m = map(int, input().split())
    for _ in range(n):
        grid.append(list(map(int, input().split())))
    ans: list[int] = list()
    for i in range(n):
        for j in range(m):
            if (grid[i][j] & (1 << 4)) == 0:
                ans.append(dfs(i, j, 4))
    ans.sort(reverse=True)
    print(*ans, end=" ")


def dfs(i: int, j: int, d: int) -> int:
    if not 0 <= i < n or not 0 <= j < m or (grid[i][j] &
                                            (1 << d)) or (grid[i][j] &
                                                          (1 << 4)):
        return 0
    grid[i][j] |= 1 << 4
    return 1 + dfs(i, j - 1, 2) + dfs(i + 1, j, 3) + dfs(i, j + 1, 0) + dfs(
        i - 1, j, 1)


if __name__ == "__main__":
    main()
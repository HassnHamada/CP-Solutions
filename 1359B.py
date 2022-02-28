import sys


def run():
    n, m, x, y = map(int, input().split())
    grid = list(input() for _ in range(n))
    ans = list(list() for _ in range(n))
    for i in range(n):
        for j in range(m):
            assert len(ans[i]) == j
            if grid[i][j] == '*':
                ans[i].append(j and ans[i][-1])
            else:
                ans[i].append((j and ans[i][-1]) + x)
                if j >= 1 and grid[i][j - 1] == '.':
                    ans[i][-1] = min(ans[i][-1], (j - 1 and ans[i][j - 2]) + y)
    print(sum(ans[i][-1] for i in range(n)))


def main():
    t = int(input())
    for _ in range(t):
        run()


if __name__ == "__main__":
    # with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
    #     sys.stdin = fin
    #     sys.stdout = fout
    #     main()
    main()

    # print(False is False == False)

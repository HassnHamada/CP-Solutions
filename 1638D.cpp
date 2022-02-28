#include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;

const int N = 1e3 + 10;
int grid[N][N];

bool ok(int i, int j)
{
    int c = -1;
    for (int ii = 0; ii < 2; ii++)
    {
        for (int jj = 0; jj < 2; jj++)
        {
            if (grid[i + ii][j + jj] == 0)
            {
                continue;
            }
            if (c != -1 && grid[i + ii][j + jj] != c)
            {
                return false;
            }
            c = grid[i + ii][j + jj];
        }
    }
    return true;
}

int getCol(int i, int j)
{
    if (grid[i][j])
    {
        return grid[i][j];
    }
    if (grid[i + 1][j])
    {
        return grid[i + 1][j];
    }
    if (grid[i][j + 1])
    {
        return grid[i][j + 1];
    }
    if (grid[i + 1][j + 1])
    {
        return grid[i + 1][j + 1];
    }
    return 0;
}

bool allZero(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // std::cout << grid[i][j] << " ";
            if (grid[i][j])
            {
                return false;
            }
        }
        // std::cout << std::endl;
    }
    return true;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (ok(i, j))
            {
                q.push({i, j});
            }
        }
    }
    std::vector<std::pair<std::pair<int, int>, int>> ans;
    while (!q.empty())
    {
        int i = q.front().first,
            j = q.front().second;
        q.pop();
        if (grid[i][j] + grid[i + 1][j] + grid[i][j + 1] + grid[i + 1][j + 1] == 0)
        {
            continue;
        }
        ans.push_back({{i + 1, j + 1}, getCol(i, j)});
        grid[i][j] = grid[i + 1][j] = grid[i][j + 1] = grid[i + 1][j + 1] = 0;
        for (int ii = std::max(0, i - 1); ii < std::min(n - 1, i + 2); ii++)
        {
            for (int jj = std::max(0, j - 1); jj < std::min(m - 1, j + 2); jj++)
            {
                if (getCol(ii, jj) && ok(ii, jj))
                {
                    q.push({ii, jj});
                }
            }
        }
    }
    if (allZero(n, m))
    {
        printf("%lld\n", ans.size());
        while (!ans.empty())
        {
            printf("%d %d %d\n", ans.back().first.first, ans.back().first.second, ans.back().second);
            ans.pop_back();
        }
    }
    else
    {
        printf("-1\n");
    }
}

int main(int argc, char const *argv[])
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t)
    while (t--)
    {
        run();
    }
    return 0;
}

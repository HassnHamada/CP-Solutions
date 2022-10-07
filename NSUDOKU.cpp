#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 30, M = N * N, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int ans[M][M], fin[M][M];

void deg(int i, int j, int n, int m, vector<bool> &out)
{
    out.resize(m);
    fill(out.begin(), out.end(), true);
    for (int k = 0; k < m; k++)
    {
        if (ans[k][j] > 0)
        {
            out[ans[k][j] - 1] = false;
        }
        if (ans[i][k] > 0)
        {
            out[ans[i][k] - 1] = false;
        }
        if (ans[k / n + i / n * n][k % n + j / n * n] > 0)
        {
            out[ans[k / n + i / n * n][k % n + j / n * n] - 1] = false;
        }
    }
}

int deg(int i, int j, int n, int m)
{
    vector<bool> tem;
    deg(i, j, n, m, tem);
    return count(tem.begin(), tem.end(), true);
}

void getfil(int n, int m, vector<tuple<int, int, int>> &out)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans[i][j] == -1)
            {
                continue;
            }
            if (ans[i][j] == 0)
            {
                out.emplace_back(deg(i, j, n, m), i, j);
            }
        }
    }
    sort(out.begin(), out.end(), greater<tuple<int, int, int>>());
}

void updtfil(int n, int m, vector<tuple<int, int, int>> &out)
{
    for (auto &&[d, x, y] : out)
    {
        d = deg(x, y, n, m);
    }
    sort(out.begin(), out.end(), greater<tuple<int, int, int>>());
}

void copy(int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fin[i][j] = ans[i][j];
        }
    }
}

bool solve(int n, int m)
{
    vector<tuple<int, int, int>> out;
    getfil(n, m, out);
    while (!out.empty())
    {
        auto [_, x, y] = out.back();
        out.pop_back();
        vector<bool> vec;
        deg(x, y, n, m, vec);
        assert(ans[x][y] == 0);
        for (int i = 0; i < m; i++)
        {
            if (vec[i])
            {
                ans[x][y] = i + 1;
                if (solve(n, m))
                {
                    return true;
                }
                if (count((int *)fin, (int *)(fin) + m * m, 0) > count((int *)ans, (int *)(ans) + m * m, 0))
                {
                    copy(m);
                }
                ans[x][y] = 0;
            }
        }
    }
    return false;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, x, y; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        scanf("%d", &ans[--x][--y]);
    }
    solve(n, n * n);
    for (int i = 0; i < n * n; i++)
    {
        for (int j = 0; j < n * n; j++)
        {
            // assert(ans[i][j]);
            printf("%d%c", fin[i][j], " \n"[j + 1 == n * n]);
        }
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}

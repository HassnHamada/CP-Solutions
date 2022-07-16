#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e1 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int ans[N][N];
int n, m;

int asd(int x, int y)
{
    return (x && ans[x - 1][y] != ans[x][y] ? 1 : 0) +
           (y && ans[x][y - 1] != ans[x][y] ? 1 : 0);
}

bool dfs(int x, int y)
{
    if (y == m)
    {
        return true;
    }
    // cout << x << " " << y << " " << ans[x][y] << endl;
    if(x && asd(x - 1, y) == )
    int c = asd(x, y);
    if (c == 0)
    {
        ans[x + 1][y] = ans[x][y + 1] = ans[x][y] ^ 1;
        if (dfs(x, y + 1))
        {
            return true;
        }
    }
    else if (c == 1)
    {
        ans[x + 1][y] = ans[x][y] ^ 1;
        ans[x][y + 1] = ans[x][y];
        if (dfs(x, y + 1))
        {
            return true;
        }
        // ans[x + 1][y] = ans[x][y];
        // ans[x][y + 1] = ans[x][y] ^ 1;
        // if (dfs(x, y + 1) || dfs(x + 1, y))
        // {
        //     return true;
        // }
    }
    else if (c == 2)
    {
        ans[x + 1][y] = ans[x][y + 1] = ans[x][y];
        if (dfs(x, y + 1))
        {
            return true;
        }
    }
    else
    {
        assert(false);
    }
    return false;
}

void run()
{
    scanf("%d%d", &n, &m);
    // cout << n << " " << m << endl;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            assert(dfs(i, 0));
        }
        for (int j = 0; j < m; j++)
        {
            printf("%d%c", ans[i][j], " \n"[j == m - 1]);
        }
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
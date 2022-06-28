#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
map<int, int> dp[N][N];
int mat[N][N];
int n, m;

int work(int i, int j, int v)
{
    if (v > (n + m - 1) / 2 || i >= n || j >= m)
    {
        return false;
    }
    if (i == n - 1 && j == m - 1)
    {
        return v + (int)(mat[i][j] == 1) == (n + m - 1) / 2;
    }
    if (dp[i][j].find(v) == dp[i][j].end())
    {
        dp[i][j].insert({v, work(i + 1, j, v + (int)(mat[i][j] == 1)) ||
                                work(i, j + 1, v + (int)(mat[i][j] == 1))});
    }
    return dp[i][j][v];
}

void run()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", (int *)(mat + i) + j);
            dp[i][j].clear();
        }
    }
    if (((n + m) & 1) && work(0, 0, 0) == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}

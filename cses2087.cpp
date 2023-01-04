#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e3 + 10, M = 1 << 12, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

ll arr[N], dp[N][N], opt[N][N], pre[N][N], suf[N][N], cst[N][N], cst_opt[N][N];

ll f(int s, int m, int e)
{

    return pre[s][m - 1] + suf[m][e];
}
ll g(int k, int s, int e)
{
    return dp[k][e] + cst[s][e];
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", arr + i);
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            pre[i][j] = arr[j] - arr[i] + pre[i][j - 1];
            suf[i][j] = (arr[j] - arr[j - 1]) * (j - i) + suf[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cst_opt[i][i + 1] = i + 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            cst_opt[j][j + i] = j + 1;
            for (int l = cst_opt[j][j + i - 1]; l <= cst_opt[j + 1][j + i]; l++)
            {
                if (f(j, cst_opt[j][j + i], j + i) > f(j, l, j + i))
                {
                    cst_opt[j][j + i] = l;
                }
            }
            cst[j][j + i] = f(j, cst_opt[j][j + i], j + i);
        }
    }
    for (int i = 0; i <= n; i++)
    {
        dp[1][i] = cst[i][n];
    }
    for (int i = 1; i < n; i++)
    {
        opt[i + 1][n - i - 1] = n - i;
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            int x = j + 1, y = n - j - i;
            assert(x >= 2 && x <= n);
            assert(y >= 0 && y < n - i);
            for (int l = max(opt[x + 1][y], opt[x][y] = y + 1); l <= opt[x][y + 1]; l++)
            {
                if (g(x - 1, y, opt[x][y]) > g(x - 1, y, l))
                {
                    opt[x][y] = l;
                }
            }
            dp[x][y] = g(x - 1, y, opt[x][y]);
        }
    }
    printf("%lld\n", dp[k][0]);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
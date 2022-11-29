#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e2 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int mat[N][N];
bool vis[N][N];

ll solve(int i, int j, int n)
{
    if (i == n && j == n)
    {
        return 0;
    }
    vis[i][j] = true;
    if (i < n && j < n)
    {
        ll ret_1 = vis[i + 1][j] ? 0 : mat[i + 1][j] + solve(i + 1, j, n),
           ret_2 = vis[i][j + 1] ? 0 : mat[i][j + 1] + solve(i, j + 1, n);
        vis[i][j] = false;
        return max(ret_1, ret_2);
    }
    else
    {
        if (i < n)
        {
            ll ret_1 = vis[i + 1][j] ? 0 : mat[i + 1][j] + solve(i + 1, j, n),
               ret_2 = vis[i][1] ? 0 : mat[i][1] + solve(i, 1, n);
            vis[i][j] = false;
            return max(ret_1, ret_2);
        }
        else
        {
            ll ret_1 = vis[1][j] ? 0 : mat[1][j] + solve(1, j, n),
               ret_2 = vis[i][j + 1] ? 0 : mat[i][j + 1] + solve(i, j + 1, n);
            vis[i][j] = false;
            return max(ret_1, ret_2);
        }
    }
}

void run()
{
    int n;
    scanf("%d", &n);
    // ll ans = 0, mn = INF;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", (int *)(mat + i) + j);
            // if (i == n - j + 1)
            // {
            //     mn = min((int)mn, mat[i][j]);
            // }
            // ans += mat[i][j];
        }
    }
    printf("%lld", mat[1][1] + solve(1, 1, n));
    // printf("%lld", ans - mn);
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
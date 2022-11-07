#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 14, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

double dp[N][N];

double solve(int n, int k, double p)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return p;
    }
    double &ret = dp[n][k];
    if (ret == ret)
    {
        return ret;
    }
    double a = 0;
    for (int i = 1; i < k; i++)
    {
        a += solve(n - 1, i, p);
    }
    return ret = p * a + k * p * solve(n - 1, k, p);
}

void run()
{
    memset(dp, -1, sizeof(dp));
    int n, k;
    scanf("%d%d", &n, &k);
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {
    //         cout << setprecision(6) << fixed;
    //         cout << solve(i, j, 1.0 / k) << " ";
    //     }
    //     cout << endl;
    // }
    double ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += solve(n, i, 1.0 / k) * i;
    }
    printf("%.6lf\n", ans);
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
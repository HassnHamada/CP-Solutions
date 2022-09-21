#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

double arr[N], dp[1 << N][N][N];

double solve(int n, int r)
{
    if (r > __builtin_popcount(n))
    {
        return 0;
    }
    if (__builtin_popcount(n) == 1)
    {
        // for (int i = 0; n >> i; i++)
        // {
        //     if ((n >> i) & 1)
        //     {
        //         return dp[n][i][r] = arr[i];
        //     }
        // }
        // assert(false);
        return 1;
    }
    double ret = 0;
    // if (ret == ret)
    // {
    //     return ret;
    // }
    cout << "in " << n << " " << r << endl;
    for (int i = 0; n >> i; i++)
    {
        if (n & (1 << i))
        {
            dp[n][i][r] = arr[i] * solve(n ^ (1 << i), r - 1);
            ret += dp[n][i][r];
        }
    }
    cout << "out " << n << " " << r << " " << ret / 2 << endl;
    return ret;
}

void run()
{
    while (true)
    {
        int n, r;
        scanf("%d%d", &n, &r);
        if (n == 0 && r == 0)
        {
            break;
        }
        memset(dp, 0, sizeof(dp[0]) * (1 << n));
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", arr + i);
        }
        solve((1 << n) - 1, r);
        // for (int i = 0; i < (1 << n); i++)
        // {
        //     for (int j = 0; j < r; j++)
        //     {
        //         cout << dp[i][j] << "\t";
        //     }
        //     cout << endl;
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     printf("%lf\n", dp[(1 << n) - 1][i][r]);
        // }
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
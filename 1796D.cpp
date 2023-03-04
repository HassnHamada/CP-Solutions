#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 21, L = 30, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N];
ll dp[M][N];

void run()
{
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    // dp[0][n] = 0;
    ll ans = dp[0][n] = 0;
    for (int j = n - 1; j >= 0; j--)
    {
        dp[0][j] = max(0ll, arr[j] - x + dp[0][j + 1]);
    }
    for (int i = 1; i <= k; i++)
    {
        dp[i][n - i] = max(0ll, arr[n - i] + x + max(0ll, dp[i - 1][n - i + 1]));
        for (int j = n - i - 1; j >= 0; j--)
        {
            dp[i][j] = max({arr[j] - x + max(0ll, dp[i][j + 1]),
                            arr[j] + x + max(0ll, dp[i - 1][j + 1]), 0ll});
        }
    }
    // for (int i = 0; i <= k; i++)
    // {
    //     for (int j = 0; j <= n - i; j++)
    //     {
    //         cout << "+-"[dp[i][j] < 0] << abs(dp[i][j]) << "\t";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i <= k; i++)
    {
        for (int j = k - i; j <= n - i; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
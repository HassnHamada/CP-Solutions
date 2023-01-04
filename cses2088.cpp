#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e3 + 10, M = 1 << 12, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

ll arr[N], dp[N][N];
int opt[N][N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", arr + i);
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        opt[i][i + 1] = i + 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            dp[j][j + i] = INT64_MAX;
            for (int k = opt[j][j + i - 1]; k <= opt[j + 1][j + i]; k++)
            {
                if (dp[j][j + i] >= dp[j][k] + dp[k][j + i] + arr[j + i] - arr[j])
                {
                    opt[j][j + i] = k;
                    dp[j][j + i] = dp[j][k] + dp[k][j + i] + arr[j + i] - arr[j];
                }
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << dp[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    printf("%lld\n", dp[0][n]);
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e1 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    // vector<double> dp(n, 1.0 / n);
    // for (int i = 1; i < m; i++)
    // {
    //     vector<double> tem(n);
    //     for (int j = 0; j < n; j++)
    //     {
    //         tem[j] = 1.0 / n * j * dp[j];
    //         if (j)
    //         {
    //             dp[j] += dp[j - 1];
    //         }
    //         tem[j] += 1.0 / n * dp[j];
    //     }
    //     swap(dp, tem);
    // }
    double ans = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     ans += dp[i] * (i + 1);
    // }
    for (int i = 1; i <= n; i++)
    {
        ans += i * (pow(1.0 * i / n, m) - pow((i - 1.0) / n, m));
    }
    printf("%.10lf\n", ans);
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
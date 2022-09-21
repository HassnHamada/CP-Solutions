#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

pair<short int, short int> arr[N];
short int dp[M][N * N][N];

void run()
{
    int n, sum_a = 0, sum_b = 0;
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        scanf("%hd%hd", &arr[i].first, &arr[i].second);
        sum_a += arr[i].first;
        sum_b += arr[i].second;
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sum_a; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (dp[i & 1][j][k] == -1)
                {
                    continue;
                }
                dp[(i + 1) & 1][j][k] = max(dp[(i + 1) & 1][j][k], dp[i & 1][j][k]);
                if (dp[i & 1][j][k] + arr[i].second > dp[(i + 1) & 1][j + arr[i].first][k + 1])
                {
                    dp[(i + 1) & 1][j + arr[i].first][k + 1] = dp[i & 1][j][k] + arr[i].second;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        double ans = 0;
        for (int j = 1; j <= sum_a; j++)
        {
            if (dp[n & 1][j][i] == -1)
            {
                continue;
            }
            ans = max(ans, min(dp[n & 1][j][i] + (sum_b - dp[n & 1][j][i]) / 2.0, j * 1.0));
        }
        printf("%.10f%c", ans, " \n"[i == n]);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
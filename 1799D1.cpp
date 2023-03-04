#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 10, M = 2, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], tem[M][N];

int n, k;
ll dp[2][N];

void solve(int p, int c)
{
    if (c <= n)
    {
        int cc = c & 1;
        memset((ll *)(dp + cc), 0x3f, sizeof(dp[0][0]) * (k + 1));
        for (int i = 0; i <= k; i++)
        {
            dp[cc][i] = min(dp[cc][i], dp[cc ^ 1][i] + tem[p == arr[c]][arr[c]]);
        }
        for (int i = 0; i <= k; i++)
        {
            if (i == arr[c])
            {
                continue;
            }
            dp[cc][p] = min(dp[cc][p], dp[cc ^ 1][i] + tem[0][arr[c]]);
        }
        dp[cc][p] = min(dp[cc][p], dp[cc ^ 1][arr[c]] + tem[1][arr[c]]);
        solve(arr[c], c + 1);
    }
}

void run()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            scanf("%d", (int *)(tem + i) + j);
        }
    }
    memset((ll *)(dp), 0x3f, sizeof(dp[0][0]) * (k + 1));
    dp[0][0] = 0;
    solve(0, 1);
    printf("%lld\n", *min_element((ll *)(dp + (n & 1)), (ll *)(dp + (n & 1)) + k + 1));
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
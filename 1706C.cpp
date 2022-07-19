#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];
ll dp[N];

ll calc(int i, int n)
{
    if (i == n)
    {
        return 0;
    }
    if (~dp[i])
    {
        return dp[i];
    }
    int mx = max(arr[i - 1], arr[i + 1]);
    if (arr[i] > mx)
    {
        return dp[i] = calc(i + 2, n);
    }
    return dp[i] = mx - arr[i] + 1 + calc(i + 2, n);
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    memset(dp, -1, sizeof(dp[0]) * n);
    if (n & 1)
    {
        printf("%lld\n", calc(1, n));
    }
    else
    {
        dp[0] = dp[n - 1] = 0;
        ll ans = min(calc(1, n), calc(2, n));
        for (int i = 3; n - i > 1; i += 2)
        {
            assert(dp[n - i] != -1);
            ans = min(ans, calc(1, n - i) - dp[n - i] + calc(n - i + 1, n));
        }
        printf("%lld\n", ans);
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
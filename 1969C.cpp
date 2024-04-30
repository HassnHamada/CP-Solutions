#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];
ll dp[N][M];

ll solve(int i, int n, int k)
{
    if (i == n)
    {
        return 0;
    }
    if (~dp[i][k])
    {
        return dp[i][k];
    }
    ll ret = 1ll * INF * INF, mn = INF;
    for (int l = 0; l <= k && i + l < n; l++)
    {
        mn = min(mn, (ll)arr[i + l]);
        ll res = solve(i + l + 1, n, k - l);
        ret = min(ret, res + mn * (l + 1));
    }
    return dp[i][k] = ret;
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    memset(dp, -1, sizeof(dp[0]) * (n + 1));
    printf("%lld\n", solve(0, n, k));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    freopen("_error.txt", "w", stderr);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
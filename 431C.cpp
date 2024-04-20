#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 8, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll dp[N];

ll solve(int n, int k, int d)
{
    assert(n >= 0);
    assert(k >= 1);
    assert(d >= 0);
    if (n == 0)
    {
        return d == 0;
    }
    ll &ret = dp[(n << 1) | (d ? 1 : 0)];
    if (~ret)
    {
        return ret;
    }
    ret = 0;
    for (int i = 1; i <= min(n, k); i++)
    {
        ret += solve(n - i, k, i >= d ? 0 : d);
        ret %= MOD;
    }
    return ret;
}

void run()
{
    int n, k, d;
    scanf("%d%d%d", &n, &k, &d);
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", solve(n, k, d));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
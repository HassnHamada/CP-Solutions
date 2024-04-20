#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int k;
ll dp[N];

ll solve(int n)
{
    if (n == 0)
    {
        return 0;
    }
    assert(n > 0);
    ll &ret = dp[n];
    if (~ret)
    {
        return ret;
    }
    ret = 1 + solve(n - 1);
    if (n >= k)
    {
        ret += 1 + solve(n - k);
    }
    return ret %= MOD;
}

void run()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%lld\n", (solve(b) - solve(a - 1) + MOD) % MOD);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    scanf("%d%d", &t, &k);
    memset(dp, -1, sizeof(dp));
    while (t--)
    {
        run();
    }
    return 0;
}
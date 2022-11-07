#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 100, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

ll arr[N], ans[N];
ll my_pow(ll b, ll p, ll m = MOD)
{
    b %= m;
    p %= (m - 1);
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = r * b % m;
        }
        p /= 2;
        b = b * b % m;
    }
    return r;
}

ll inv(ll b)
{
    return my_pow(b, MOD - 2);
}

ll solve(int cz, int tz, int n)
{
    if (cz == tz)
    {
        return 0;
    }
    assert(cz < tz);
    if (~ans[cz])
    {
        return ans[cz];
    }
    ll p = 1ll * (tz - cz) * (tz - cz) % MOD * inv(1ll * n * (n - 1) / 2) % MOD;
    // dp[cz] = 1 + dp[cz] * (1 - p) + dp[cz + 1] * p;
    // dp[cz] - dp[cz] * (1 - p) = 1 + dp[cz + 1] * p;
    // dp[cz] * (1 - (1 - p)) = 1 + dp[cz + 1] * p;
    // dp[cz] * (1 - 1 + p) = 1 + dp[cz + 1] * p;
    // dp[cz] * p = 1 + dp[cz + 1] * p;
    // dp[cz] = 1/p + dp[cz + 1];
    return ans[cz] = (inv(p) + solve(cz + 1, tz, n)) % MOD;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
    }
    int z = count(arr, arr + n, 0);
    memset(ans, -1, sizeof(ans[0]) * z);
    printf("%lld\n", solve(count(arr, arr + z, 0), z, n));
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
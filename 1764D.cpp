#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e3 + 10, M = 128, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll solve(int n, int d, int sz, int mod, int m = 3, int p = -1)
{
    if (n == sz)
    {
        return d + p == m;
    }
    if (d == m)
    {
        return 1;
    }
    ll ret = solve(n + 1, d + 1, sz, mod, m, p);
    ret += solve(n + 1, 0, sz, mod, m, ~p ? p : d);
    ret %= mod;
    return ret;
}

ll fact[N], ifact[N], inv[N];

void run()
{
    int n, p;
    scanf("%d%d", &n, &p);
    fact[0] = fact[1] = ifact[0] = ifact[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i % p;
        inv[i] = (p - (p / i) * inv[p % i] % p) % p;
        ifact[i] = ifact[i - 1] * inv[i] % p;
    }
    ll ans = 0;
    for (int i = 1, j = -1; i < n; i++)
    {
        if (2 * (i + 1) <= n)
        {
            continue;
        }
        if (j == -1)
        {
            j = i;
        }
        assert(i <= 2 * j);
        ll res = solve(0, 0, n, p, i);
        for (int k = 0; k <= i - j; k++)
        {
            res = res * fact[j - k] * fact[k] % p;
        }
        ans = (ans + res) % p;
    }
    printf("%lld\n", ans);
    // assert(bit.get_range(0, n - 1) == 0);
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
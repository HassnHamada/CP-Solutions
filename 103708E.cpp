#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 2e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
ll fact[N], ifact[N], inv[N];

void factPre()
{
    fact[0] = fact[1] = ifact[0] = ifact[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
        ifact[i] = ifact[i - 1] * inv[i] % MOD;
    }
}

ll nPr(int n, int r)
{
    if (r > n)
    {
        return 0;
    }
    return fact[n] * ifact[n - r] % MOD;
}

ll nCr(int n, int r)
{
    if (r > n)
    {
        return 0;
    }
    return fact[n] * ifact[n - r] % MOD * ifact[r] % MOD;
}

ll my_pow(ll b, int p)
{
    ll ret = 1;
    while (p)
    {
        if (p & 1)
        {
            ret = ret * b;
        }
        b = b * b;
        p /= 2;
    }
    return ret;
}

void run()
{
    factPre();
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    printf("%lld\n", k > n ? 0ll : nCr(m, k));
    printf("%lld\n", k > n ? 0ll : nPr(k, k));
    printf("%lld\n", k > n ? 0ll : nCr(n, k));
    printf("%lld\n", k > n ? 0ll : my_pow(k, n - k));
    printf("%lld\n", k > n ? 0ll : my_pow(k, n - k) * nCr(n, k) * nPr(k, k) % MOD * nCr(m, k) % MOD);
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
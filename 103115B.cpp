#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4e5 + 10, M = 2e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll fact[N], ifact[N], inv[N];

void pre()
{
    fact[0] = fact[1] = ifact[0] = ifact[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
        ifact[i] = ifact[i - 1] * inv[i] % MOD;
    }
}

int nCr(int n, int r)
{
    return fact[n] * ifact[n - r] % MOD * ifact[r] % MOD;
}

ll my_pow(ll b, ll p, ll m = MOD)
{
    ll ret = 1;
    while (p)
    {
        if (p & 1)
        {
            ret = ret * b % m;
        }
        b = b * b % m;
        p >>= 1;
    }
    return ret;
}

void run()
{
    pre();
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    while (q--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%lld\n", nCr(a + b - 1, a == n ? b : a) * my_pow(2, n + m - a - b) % MOD);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
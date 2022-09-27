#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 3, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

ll arr[N];
ll fact[N], ifact[N], inv[N];

ll my_pow(ll b, ll p, ll m = MOD)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = r * b % m;
        }
        b = b * b % m;
        p = p / 2;
    }
    return r;
}

ll nCr(int n, int r)
{
    return fact[n] * ifact[n - r] % MOD * ifact[r] % MOD;
}

ll nPr(int n, int r)
{
    return fact[n] * ifact[n - r] % MOD;
}

void run()
{
    fact[0] = fact[1] = ifact[0] = ifact[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
        ifact[i] = ifact[i - 1] * inv[i] % MOD;
    }
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", arr + i);
        arr[i] += arr[i - 1];
    }
    int d = 0;
    if (arr[n] % 2 == 0)
    {
        for (int i = 1; i <= n && arr[i] <= arr[n] / 2; i++)
        {
            auto it = lower_bound(arr + 1, arr + n + 1, arr[i] + arr[n] / 2);
            if (it != arr + n + 1)
            {
                d += (*it) == arr[i] + arr[n] / 2;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= min(m, d); i++)
    {
        ans = (ans + nCr(d, i) * nPr(m, i) % MOD * my_pow(nPr(m - i, 2), d - i) % MOD * my_pow(m - i, n - 2 * d) % MOD) % MOD;
    }
    printf("%d", ans);
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
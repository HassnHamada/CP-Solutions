#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 14, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

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

ll nCr(int n, int r)
{
    // if (n == 0 || r == 0)
    // {
    //     return 1;
    // }
    return fact[n] * ifact[n - r] % MOD * ifact[r] % MOD;
}

char str[N];

void run()
{
    pre();
    int n;
    scanf("%d", &n);
    bool ok = (n & 1) == 0;
    scanf("%s", str);
    int x = 0, y = 0;
    for (int i = 0; ok && str[i]; i++)
    {
        x += str[i] == '(';
        y += str[i] == ')';
        ok = x >= y;
    }

    if (ok)
    {
        cerr << nCr(n - x - y, n / 2 - x) << endl;
        cerr << nCr(n - x - y, n / 2 - y) << endl;
        cerr << nCr(n - x - y, n / 2 - x - 1) << endl;
        cerr << nCr(n - x - y, n / 2 - y + 1) << endl;
    }
    printf("%lld\n", ok ? (nCr(n - x - y, n / 2 - x) - nCr(n - x - y, n / 2 - x - 1) + MOD) % MOD : 0ll);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
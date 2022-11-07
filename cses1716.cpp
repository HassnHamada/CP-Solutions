#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 10, M = 14, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;



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

void run()
{
    pre();
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", nCr(m + n - 1, n - 1));
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
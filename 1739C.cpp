#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 61, M = 3, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

ll dp[N][M];
ll fact[N], ifact[N], inv[N];

ll nCr(int n, int r)
{
    return fact[n] * ifact[n - r] % MOD * ifact[r] % MOD;
}

void pre()
{
    fact[0] = fact[1] = ifact[0] = ifact[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
        ifact[i] = ifact[i - 1] * inv[i] % MOD;
    }
    dp[0][2] = dp[2][0] = dp[2][2] = 1;
    for (int i = 4; i < N; i += 2)
    {
        dp[i][0] = nCr(i - 1, i / 2 - 1);
        dp[i][1] = nCr(i - 2, i / 2 - 2);
        dp[i][0] = (dp[i][0] + dp[i - 2][1]) % MOD;
        dp[i][1] = (dp[i][1] + dp[i - 2][0]) % MOD;
        dp[i][2] = (dp[i][2] + dp[i - 2][2]) % MOD;
    }
}

void run()
{
    int n;
    scanf("%d", &n);
    printf("%lld %lld %lld\n", dp[n][0], dp[n][1], dp[n][2]);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    pre();
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}

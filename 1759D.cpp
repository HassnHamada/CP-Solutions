#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e1 + 10, M = 100, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

ll pow2[M], pow5[M], dp[M][M];

void pre()
{
    pow2[0] = pow5[0] = 1;
    for (int i = 1; i <= 60; i++)
    {
        pow2[i] = 2 * pow2[i - 1];
    }
    for (int i = 1; i <= 26; i++)
    {
        pow5[i] = 5 * pow5[i - 1];
    }
}

int solve(int t, int f, ll m)
{
    assert(t < 60);
    assert(f < 26);
    if (~dp[t][f])
    {
        return dp[t][f];
    }
    int ret = min(t, f);
    if (pow2[t + 1] <= m && pow2[t + 1] * pow5[f] <= m)
    {
        ret = max(ret, solve(t + 1, f, m));
    }
    if (pow5[f + 1] <= m && pow2[t] * pow5[f + 1] <= m)
    {
        ret = max(ret, solve(t, f + 1, m));
    }
    return dp[t][f] = ret;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int t = 0, f = 0;
    int v = n;
    while (v % 2 == 0)
    {
        t++;
        v /= 2;
    }
    v = n;
    while (v % 5 == 0)
    {
        f++;
        v /= 5;
    }
    v = m;
    int et = 0, ef = 0;
    while (v >= 2 && t + et < f)
    {
        et++;
        v /= 2;
    }
    while (v >= 5 && f + ef < t)
    {
        ef++;
        v /= 5;
    }
    memset(dp, -1, sizeof(dp));
    int z = solve(0, 0, v);
    printf("%lld\n", 1ll * n * (m / pow2[et + z] / pow5[ef + z]) * pow2[et + z] * pow5[ef + z]);
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

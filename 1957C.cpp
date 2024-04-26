#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll dp[N];

void pre()
{
    dp[0] = dp[1] = 1;
    for (int i = 2; i < N; i++)
    {
        dp[i] = (dp[i - 1] + 2 * (i - 1) * dp[i - 2]) % MOD;
    }
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0, x, y; i < k; i++)
    {
        scanf("%d%d", &x, &y);
        n -= 2 - (x == y);
    }
    printf("%lld\n", dp[n]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    pre();
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
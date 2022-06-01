#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e3 + 5, MOD = 32768, HV = 151, INF = 0x3f3f3f3f;
int www[N], vvv[N], dp[N][N];

int solve(int n, int s)
{

    if (!~n)
    {
        return 0;
    }
    if (~dp[n][s])
    {
        return dp[n][s];
    }
    dp[n][s] = solve(n - 1, s);
    if (www[n] <= s)
    {
        dp[n][s] = max(dp[n][s], solve(n - 1, s - www[n]) + vvv[n]);
    }
    return dp[n][s];
}

void run()
{
    int s, n;
    scanf("%d%d", &s, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", www + i, vvv + i);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(n - 1, s));
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
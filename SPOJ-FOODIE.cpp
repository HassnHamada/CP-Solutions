#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 5, M = 1e3 + 5, MOD = 32768, HV = 151, INF = 0x3f3f3f3f;
int www[N], dp[N][M];

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
        dp[n][s] = max(dp[n][s], solve(n - 1, s - www[n]) + www[n]);
    }
    return dp[n][s];
}

void run()
{
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 0, m; i < n; i++)
    {
        www[i] = 0;
        scanf("%d", &m);
        for (int j = 0, v; j < m; j++)
        {
            scanf("%d", &v);
            www[i] += v;
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(n - 1, s));
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> adj[N];
ll dp[N];
int sz[N];

int calc_sz(int n, int p)
{
    for (auto &&i : adj[n])
    {
        if (i == p)
        {
            continue;
        }
        sz[n] += calc_sz(i, n);
    }
    return ++sz[n];
}

ll calc_dp(int n, int p)
{
    for (auto &&i : adj[n])
    {
        if (i == p)
        {
            continue;
        }
        dp[n] += calc_dp(i, n);
    }
    return dp[n] += sz[n];
}

ll solve(int n, int p)
{
    ll ret = dp[n];
    for (auto &&i : adj[n])
    {
        if (i == p)
        {
            continue;
        }
        dp[n] -= dp[i];
        dp[n] -= sz[i];
        sz[n] -= sz[i];
        sz[i] += sz[n];
        dp[i] += sz[n];
        dp[i] += dp[n];

        ret = max(ret, solve(i, n));
        
        dp[i] -= dp[n];
        dp[i] -= sz[n];
        sz[i] -= sz[n];
        sz[n] += sz[i];
        dp[n] += sz[i];
        dp[n] += dp[i];
    }
    return ret;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    calc_sz(1, 0);
    calc_dp(1, 0);
    printf("%lld\n", solve(1, 0));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    freopen("_error.txt", "w", stderr);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
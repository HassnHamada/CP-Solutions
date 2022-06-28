#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
vector<int> tre[N];
int n;
map<int, int> dp[N];

int dfs(int c, int p)
{
    if (dp[c].find(p) != dp[c].end())
    {
        return dp[c][p];
    }
    int ret = 0, chl = 0;
    for (auto &&i : tre[c])
    {
        if (i == p)
        {
            continue;
        }
        int res = dfs(i, c);
        if (res == 0)
        {
            chl += 1;
        }
        ret += res;
    }
    return dp[c][p] = ret + max(0, chl - 1);
}

void run()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        tre[i].clear();
        dp[i].clear();
        // memset((int *)(dp + i), -1, sizeof(dp[0][0]) * (n + 1));
    }
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    int ans = INF;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dfs(i, 0) + 1);
    }
    if (n == 1)
    {
        ans = 0;
    }
    printf("%d\n", ans);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}

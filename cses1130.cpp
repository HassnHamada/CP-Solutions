#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

vector<int> tre[N];
int dp[N][M];

int dfs(int n, int p, bool s = false)
{
    if (~dp[n][s])
    {
        return dp[n][s];
    }
    int ret_1 = 0;
    for (auto &&i : tre[n])
    {
        if (i == p)
        {
            continue;
        }
        ret_1 += dfs(i, n);
    }
    int ret_2 = 0;
    if (!s)
    {
        for (auto &&i : tre[n])
        {
            if (i == p)
            {
                continue;
            }
            ret_2 = max(ret_2, ret_1 - dfs(i, n) + dfs(i, n, true) + 1);
        }
    }
    return dp[n][s] = max(ret_1, ret_2);
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    printf("%d\n", dfs(1, 0));
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
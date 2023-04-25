#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N];
bool vis[N], stk[N];

bool dfs(int n, vector<int> &ans)
{
    assert(!vis[n]);
    stk[n] = vis[n] = true;
    for (auto &&i : grf[n])
    {
        if (stk[i])
        {
            return false;
        }
        if (vis[i])
        {
            continue;
        }
        if (!dfs(i, ans))
        {
            return false;
        }
    }
    stk[n] = false;
    ans.push_back(n);
    return true;
}

void run()
{
    int n, m;
    while (scanf("%d%d", &n, &m), n)
    {
        for (int i = 0, u, v; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            grf[u].push_back(v);
        }
        bool ok = true;
        vector<int> ans;
        memset(vis, 0, sizeof(vis[0]) * (n + 1));
        memset(stk, 0, sizeof(stk[0]) * (n + 1));
        for (int i = 1; ok && i <= n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            ok = dfs(i, ans);
        }
        if (ok)
        {
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < n; i++)
            {
                printf("%d\n", ans[i]);
            }
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
        for (int i = 1; i <= n; i++)
        {
            grf[i].clear();
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
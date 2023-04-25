#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N];
bool vis[N];

void dfs(int n, vector<int> &ans)
{
    assert(!vis[n]);
    vis[n] = true;
    for (auto &&i : grf[n])
    {
        if (vis[i])
        {
            continue;
        }
        dfs(i, ans);
    }
    ans.push_back(n);
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
        vector<int> ans;
        memset(vis, 0, sizeof(vis[0]) * (n + 1));
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            dfs(i, ans);
        }
        reverse(ans.begin(), ans.end());
        assert((int)ans.size() == n);
        for (int i = 0; i < n; i++)
        {
            printf("%d%c", ans[i], " \n"[i + 1 == n]);
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
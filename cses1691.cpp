#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 2e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[N << 1], vis[N << 1], vid;
vector<int> grf[N];
pair<int, int> edg[N << 1];

void dfs(int n)
{
    vis[n] = vid;
    for (auto &&i : grf[n])
    {
        int j = edg[i].first == n ? edg[i].second : edg[i].first;
        if (vis[j] == vid)
        {
            continue;
        }
        dfs(j);
    }
}

bool ok(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (grf[i].size() & 1)
        {
            return false;
        }
    }
    vid++;
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (!grf[i].empty() && vis[i] != vid)
        {
            return false;
        }
    }
    return true;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u].push_back(i);
        grf[v].push_back(i);
        edg[i] = {u, v};
    }
    if (ok(n))
    {
        int sz = 0;
        stack<int> stk;
        stk.push(1);
        vid++;
        while (!stk.empty())
        {
            int t = stk.top();
            if (grf[t].empty())
            {
                stk.pop();
                ans[sz++] = t;
                continue;
            }
            int i = grf[t].back();
            if (vis[i] == vid)
            {
                grf[t].pop_back();
                continue;
            }
            int j = edg[i].first == t ? edg[i].second : edg[i].first;
            stk.push(j);
            vis[i] = vid;
            grf[t].pop_back();
        }
        assert(sz == m + 1);
        for (int i = 0; i < sz; i++)
        {
            printf("%d%c", ans[i], " \n"[i + 1 == sz]);
        }
    }
    else
    {
        printf("IMPOSSIBLE\n");
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
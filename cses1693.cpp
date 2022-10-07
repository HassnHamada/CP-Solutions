#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 15, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
vector<int> grf[N];
int ans[N << 1], deg[N];
bool vis[N], in[N];

void dfs(int c)
{
    vis[c] = true;
    for (auto &&i : grf[c])
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
}

bool ok(int n)
{
    if (deg[0] != 1 || deg[n - 1] != -1)
    {
        return false;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (in[i] && deg[i] != 0)
        {
            return false;
        }
    }
    dfs(0);
    for (int i = 0; i < n; i++)
    {
        if (in[i] && !vis[i])
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
        in[--u] = in[--v] = true;
        grf[u].push_back(v);
        deg[u]++;
        deg[v]--;
    }
    if (ok(n))
    {
        int sz = 0;
        stack<int> stk;
        stk.push(0);
        while (!stk.empty())
        {
            int t = stk.top();
            if (grf[t].empty())
            {
                ans[sz++] = t + 1;
                stk.pop();
                continue;
            }
            stk.push(grf[t].back());
            grf[t].pop_back();
        }
        for (int i = sz - 1; ~i; i--)
        {
            printf("%d%c", ans[i], " \n"[i == 0]);
        }
    }
    else
    {
        printf("IMPOSSIBLE\n");
    }
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
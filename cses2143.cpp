#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

const int N = 5e4 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

vector<int> grf[N], dag[N];
int ids[N], low[N], cyc[N], id, cid;
bool onStk[N];
stack<int> stk;
bitset<N> ans[N];

void dfs(int c)
{
    low[c] = ids[c] = id++;
    onStk[c] = true;
    stk.push(c);
    for (auto &&i : grf[c])
    {
        if (ids[i] == EMP)
        {
            dfs(i);
        }
        if (onStk[i])
        {
            low[c] = min(low[c], low[i]);
        }
    }
    if (low[c] == ids[c])
    {
        cyc[c] = cid++;
        while (true)
        {
            int t = stk.top();
            stk.pop();
            onStk[t] = false;
            cyc[t] = cyc[c];
            low[t] = low[c];
            if (t == c)
            {
                break;
            }
        }
    }
}

void tarjan(int n)
{
    for (int i = 1; i <= n; i++)
    {
        ids[i] = EMP;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ids[i] == EMP)
        {
            dfs(i);
        }
    }
}

void dfs_2(int n)
{
    ans[n][n] = 1;
    for (auto &&i : dag[n])
    {
        if (ans[i][i] == 0)
        {
            dfs_2(i);
        }
        ans[n] |= ans[i];
    }
}

void run()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u].push_back(v);
    }
    tarjan(n);
    for (int i = 1; i <= n; i++)
    {
        for (auto &&j : grf[i])
        {
            dag[cyc[i]].push_back(cyc[j]);
        }
    }
    for (int i = 0; i < cid; i++)
    {
        sort(dag[i].begin(), dag[i].end());
        dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
    }
    for (int i = 0; i < cid; i++)
    {
        if (ans[i][i] == 0)
        {
            dfs_2(i);
        }
    }
    for (int i = 0, u, v; i < q; i++)
    {
        scanf("%d%d", &u, &v);
        printf(cyc[u] == cyc[v] || ans[cyc[u]][cyc[v]] ? "YES\n" : "NO\n");
    }
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
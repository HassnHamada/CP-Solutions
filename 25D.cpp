#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> adj[N];
bool vis[N], stk[N];
vector<pair<int, int>> rm;
vector<int> dsu;

void dfs(int n, int p)
{
    vis[n] = stk[n] = true;
    for (auto &&i : adj[n])
    {
        if (i == p)
        {
            continue;
        }
        if (vis[i])
        {
            if (stk[i])
            {
                rm.emplace_back(n, i);
            }
            continue;
        }
        dfs(i, n);
    }
    stk[n] = false;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        dsu.push_back(i);
        dfs(i, 0);
    }
    for (auto &&i : dsu)
    {
        fprintf(stderr, "treeId %d\n", i);
    }
    for (auto &&[i, j] : rm)
    {
        fprintf(stderr, "rm %d %d\n", i, j);
    }
    assert(rm.size() == dsu.size() - 1);
    printf("%d\n", (int)rm.size());
    for (auto &&[i, j] : rm)
    {
        int u = dsu.back();
        dsu.pop_back();
        printf("%d %d %d %d\n", i, j, u, dsu.back());
    }
    assert(dsu.size() == 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
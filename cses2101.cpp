#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e3 + 10, M = 1 << 12, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

struct DSU
{
    vector<int> per;
    void init(int n)
    {
        per.resize(n);
        iota(per.begin(), per.end(), 0);
    }
    void join(int a, int b)
    {
        per[b = find(b)] = a = find(a);
    }
    int find(int a)
    {
        return a == per[a] ? a : per[a] = find(per[a]);
    }
    bool isCon(int a, int b)
    {
        return find(a) == find(b);
    }
} dsu;

vector<vector<pair<int, int>>> tre, lca;
vector<bool> vis;
vector<int> lvl;

void dfs(int n, int p)
{
    assert(!vis[n]);
    vis[n] = true;
    lvl[n] = lvl[p] + 1;
    for (auto &&[i, j] : tre[n])
    {
        if (i == p)
        {
            continue;
        }
        dfs(i, n);
        lca[0][i] = {n, j};
    }
}

int solve(int u, int v)
{
    if (lvl[u] < lvl[v])
    {
        swap(u, v);
    }
    int u_mx = 0, v_mx = 0, lg_n = lca.size();
    for (int i = lg_n - 1; ~i; i--)
    {
        if (lvl[lca[i][u].first] >= lvl[v])
        {
            u_mx = max(u_mx, lca[i][u].second);
            u = lca[i][u].first;
        }
    }
    assert(lvl[u] == lvl[v]);
    if (u == v)
    {
        return u_mx;
    }
    for (int i = lg_n - 1; ~i; i--)
    {
        if (lca[i][u].first != lca[i][v].first)
        {
            u_mx = max(u_mx, lca[i][u].second);
            v_mx = max(v_mx, lca[i][v].second);
            u = lca[i][u].first;
            v = lca[i][v].first;
        }
    }
    assert(lca[0][u].first == lca[0][v].first);
    return max({u_mx, v_mx, lca[0][u].second, lca[0][v].second});
}

void run()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    dsu.init(n + 1);
    tre.assign(n + 1, vector<pair<int, int>>());
    vis.assign(n + 1, false);
    lvl.assign(n + 1, 0);
    for (int i = 1, u, v; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        if (!dsu.isCon(u, v))
        {
            dsu.join(u, v);
            tre[u].emplace_back(v, i);
            tre[v].emplace_back(u, i);
        }
    }
    int lg_n = log2(n << 1);
    lca.assign(lg_n, vector<pair<int, int>>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        dfs(i, 0);
    }
    for (int i = 1; i < lg_n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            lca[i][j] = {lca[i - 1][lca[i - 1][j].first].first,
                         max(lca[i - 1][j].second, lca[i - 1][lca[i - 1][j].first].second)};
        }
    }
    for (int i = 1, u, v; i <= q; i++)
    {
        scanf("%d%d", &u, &v);
        if (dsu.isCon(u, v))
        {
            printf("%d\n", solve(u, v));
        }
        else
        {
            printf("-1\n");
        }
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
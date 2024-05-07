#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <stdio.h>
#include <vector>
#include <numeric>
#include <assert.h>
#endif
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20;

tuple<int, int, int, int> edges[N];
vector<tuple<int, int>> tre[N];
pair<int, int> lca[M][N];
int lvl[N];
ll ans[N];

struct DSU
{
    int n, per[N], sz[N];
    void init(int _n)
    {
        this->n = _n;
        iota(per, per + _n, 0);
        fill(sz, sz + _n, 1);
    }
    int find(int a)
    {
        return a == per[a] ? a : per[a] = find(per[a]);
    }
    bool isCon(int a, int b)
    {
        return find(a) == find(b);
    }
    void join(int a, int b)
    {
        if (isCon(a, b))
        {
            return;
        }
        n -= 1;
        a = find(a), b = find(b);
        if (sz[a] > sz[b])
        {
            per[b] = a;
            sz[a] += sz[b];
        }
        else
        {
            per[a] = b;
            sz[b] += sz[a];
        }
    }
} dsu;

ll mst(int n, int m)
{
    ll w = 0;
    dsu.init(n + 1);
    sort(edges, edges + m);
    for (int i = 0; i < m; i++)
    {
        auto &[c, u, v, j] = edges[i];
        if (dsu.isCon(u, v))
        {
            continue;
        }
        dsu.join(u, v);
        tre[u].emplace_back(v, c);
        tre[v].emplace_back(u, c);
        w += c;
    }
    return w;
}

void dfs(int u, int p)
{
    for (auto &&[i, j] : tre[u])
    {
        if (i == p)
        {
            continue;
        }
        lvl[i] = lvl[u] + 1;
        lca[0][i] = {u, j};
        dfs(i, u);
    }
}

int get_max(int a, int b)
{
    int ret = 0;
    if (lvl[b] > lvl[a])
    {
        swap(a, b);
    }
    assert(lvl[a] >= lvl[b]);
    for (int i = M - 1; ~i && lvl[a] > lvl[b]; i--)
    {
        if (lca[i][a].first == 0 || lvl[lca[i][a].first] < lvl[b])
        {
            continue;
        }
        ret = max(ret, lca[i][a].second);
        a = lca[i][a].first;
    }
    assert(lvl[a] == lvl[b]);
    if (a == b)
    {
        return ret;
    }
    for (int i = M - 1; ~i; i--)
    {
        if (lca[i][a].first == lca[i][b].first)
        {
            continue;
        }
        ret = max({ret, lca[i][a].second, lca[i][b].second});
        a = lca[i][a].first;
        b = lca[i][b].first;
    }
    assert(lca[0][a].first == lca[0][b].first);
    return max({ret, lca[0][a].second, lca[0][b].second});
    ;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v, c; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        edges[i] = {c, u, v, i};
    }
    ll w = mst(n, m);
    dfs(1, 0);
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            lca[i][j] = {lca[i - 1][lca[i - 1][j].first].first,
                         max(lca[i - 1][j].second, lca[i - 1][lca[i - 1][j].first].second)};
        }
    }
    for (int i = 0; i < m; i++)
    {
        auto &[c, u, v, j] = edges[i];
        ans[j] = w - get_max(u, v) + c;
    }
    for (int i = 0; i < m; i++)
    {
        printf("%lld\n", ans[i]);
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
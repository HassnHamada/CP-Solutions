#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 10, M = 14, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], sz[N], hvy[N], ids[N], id, hed[N], per[N][M], seg[1 << M], dep[N];
vector<pair<int, int>> tre[N];

void dfs(int n, int p)
{
    sz[n] = 1;
    hvy[n] = -1;
    per[n][0] = p;
    dep[n] = dep[p] + 1;
    for (auto &&[i, j] : tre[n])
    {
        if (i == p)
        {
            continue;
        }
        arr[i] = j;
        dfs(i, n);
        sz[n] += sz[i];
        if (hvy[n] == -1 || sz[i] > sz[hvy[n]])
        {
            hvy[n] = i;
        }
    }
}

void hld(int n, int p, int h)
{
    hed[n] = h;
    ids[n] = id++;
    seg[n] = seg[h];
    if (~hvy[n])
    {
        hld(hvy[n], n, h);
    }
    for (auto &&[i, j] : tre[n])
    {
        if (i == p || i == hvy[n])
        {
            continue;
        }
        hld(i, n, i);
    }
}

pair<int, int> lca(int a, int b)
{
    for (int i = M - 1; ~i; i--)
    {
        if (dep[per[a][i]] >= dep[b])
        {
            a = per[a][i];
        }
        if (dep[per[b][i]] >= dep[a])
        {
            b = per[b][i];
        }
    }
    assert(dep[a] == dep[b]);
    if (a != b)
    {
        for (int i = M - 1; ~i; i--)
        {
            if (per[a][i] != per[b][i])
            {
                a = per[a][i];
                b = per[b][i];
            }
        }
        assert(per[a][0] == per[b][0]);
    }
    return {a, b};
}

int lca_(int a, int b)
{
    assert(dep[a] < dep[b]);
    for (int i = M - 1; ~i; i--)
    {
        if (dep[per[b][i]] > dep[a])
        {
            b = per[b][i];
        }
    }
    assert(per[b][0] == a);
    return b;
}

void update(int qi, int qv, int i, int s, int e)
{
    if (qi < s || qi > e)
    {
        return;
    }
    if (s == e)
    {
        assert(qi == s);
        seg[i] = qv;
        return;
    }
    int l = 2 * i + 1, r = l + 1, m = (e + s) / 2;
    update(qi, qv, l, s, m);
    update(qi, qv, r, m + 1, e);
    seg[i] = max(seg[l], seg[r]);
}

int query_(int qs, int qe, int i, int s, int e)
{
    if (qe < s || qs > e)
    {
        return INT32_MIN;
    }
    if (s >= qs && e <= qe)
    {
        return seg[i];
    }
    int l = 2 * i + 1, r = l + 1, m = (e + s) / 2;
    return max(query_(qs, qe, l, s, m), query_(qs, qe, r, m + 1, e));
}

int query(int a, int b, int n)
{
    int ans = INT32_MIN;
    while (hed[a] != hed[b])
    {
        if (dep[a] < dep[b])
        {
            swap(a, b);
        }
        ans = max(ans, query_(ids[hed[a]], ids[a], 0, 0, n - 1));
        a = per[hed[a]][0];
    }
    if (dep[a] < dep[b])
    {
        swap(a, b);
    }
    assert(ids[b] <= ids[a]);
    ans = max(ans, query_(ids[b], ids[a], 0, 0, n - 1));
    return ans;
}

char buf[N];
pair<int, int> edg[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v, w; i < n - 1; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        tre[u].emplace_back(v, w);
        tre[v].emplace_back(u, w);
        edg[i] = {u, v};
    }
    dfs(1, 0);
    hld(1, 0, 1);
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            per[j][i] = per[per[j][i - 1]][i - 1];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        update(ids[i], arr[i], 0, 0, n - 1);
    }
    while (true)
    {
        scanf("%s", buf);
        if (buf[0] == 'C')
        {
            int s, x;
            scanf("%d%d", &s, &x);
            auto [c, d] = edg[s - 1];
            assert(abs(dep[c] - dep[d]) == 1);
            update(ids[dep[c] > dep[d] ? c : d], x, 0, 0, n - 1);
        }
        else if (buf[0] == 'Q')
        {
            int a, b;
            scanf("%d%d", &a, &b);
            assert(a != b);
            auto [c, d] = lca(a, b);
            if (c == d)
            {
                assert(dep[a] != dep[b]);
                if (dep[a] > dep[b])
                {
                    swap(a, b);
                }
                printf("%d\n", query(lca_(a, b), d, n));
            }
            else
            {
                printf("%d\n", max(query(c, a, n), query(d, b, n)));
            }
        }
        else if (buf[0] == 'D')
        {
            break;
        }
        else
        {
            assert(false);
        }
    }
    id = 0;
    for (int i = 1; i <= n; i++)
    {
        tre[i].clear();
    }
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 18, L = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> tre[N];
int lvl[N], anc[N][M], arr[N];

void dfs(int n = 1, int p = 0)
{
    // cout << n << " " << p << " " << l << " " << tre[n].size() << endl;
    lvl[n] = lvl[p] + 1;
    anc[n][0] = p;
    for (auto &&i : tre[n])
    {
        if (i == p)
        {
            continue;
        }
        dfs(i, n);
    }
}

int lca(int a, int b)
{
    // cout << "sdasdasd " << a << " " << b << endl;
    for (int i = M - 1; ~i; i--)
    {
        // cout << a << " " << lvl[a] << " " << b << " " << lvl[b] << endl;
        if (lvl[a] == lvl[b])
        {
            continue;
        }
        else if (lvl[anc[a][i]] >= lvl[b])
        {
            a = anc[a][i];
        }
        else if (lvl[anc[b][i]] >= lvl[a])
        {
            b = anc[b][i];
        }
    }
    // cout << "4646das " << a << " " << b << endl;
    assert(lvl[a] == lvl[b]);
    if (a == b)
    {
        return a;
    }
    for (int i = M - 1; ~i; i--)
    {
        if (anc[a][i] == anc[b][i])
        {
            continue;
        }
        a = anc[a][i];
        b = anc[b][i];
    }
    assert(lvl[a] == lvl[b]);
    assert(anc[a][0] == anc[b][0]);
    return anc[a][0];
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
    lvl[0] = -1;
    dfs();
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            anc[j][i] = anc[anc[j][i - 1]][i - 1];
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int m, t = 1;
        scanf("%d", &m);
        // cout << q + 1 << " " << m << endl;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", arr + i);
            if (lvl[arr[i]] > lvl[t])
            {
                t = arr[i];
            }
        }
        int h = t, e = -1;
        bool ok = true;
        for (int i = 0; ok && i < m; i++)
        {
            int v = lca(arr[i], t);
            if (lvl[v] < lvl[h])
            {
                h = v;
            }
            if (v == arr[i])
            {
                continue;
            }
            if (e == -1)
            {
                e = arr[i];
            }
            int w = lca(e, arr[i]);
            if (w == e || w == arr[i])
            {
                if (lvl[arr[i]] > lvl[e])
                {
                    e = arr[i];
                }
                continue;
            }
            ok = false;
        }
        if (ok && ~e && lca(e, t) != h)
        {
            ok = false;
        }
        printf(ok ? "YES\n" : "NO\n");
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

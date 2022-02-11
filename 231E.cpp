#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e5 + 10, M = 2e5 + 10, L = 20, MOD = 1e9 + 7;
vector<int> tre[N];
int vis[N], cyc[N], dne[N], anc[N][L], lvl[N], blk[N], clc[N];
map<int, int> mmm;

struct ADJ
{
    int sz, head[N], nxt[M], to[M], ne;

    void addEdge(int f, int t)
    {
        assert(ne + 1 < M);
        assert(f < sz && t < sz);
        nxt[ne] = head[f];
        to[ne] = t;
        head[f] = ne++;
    }

    void addBiEdge(int f, int t)
    {
        addEdge(f, t);
        addEdge(t, f);
    }

    int addNode()
    {
        head[sz] = -1;
        return sz++;
    }

    void init(int n)
    {
        this->sz = n;
        memset(head, -1, n * sizeof head[0]);
        ne = 0;
    }
    void prn()
    {
        for (int i = 0; i < ne; i += 2)
        {
            cout << (this->to[i]) << " " << (this->to[i ^ 1]) << endl;
        }
    }
} grf, sqz;

int asd(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (mmm.find(cyc[i]) == mmm.end())
        {
            mmm.emplace(i, mmm.size());
        }
    }
    for (int i = 0; i < n; i++)
    {
        blk[mmm[cyc[i]]] = blk[i];
        cyc[i] = mmm[cyc[i]];
    }
    return mmm.size();
}

void dfs(int n = 0, int p = -1, int vid = 1)
{
    // cout << n << " " << p << " " << vid << endl;
    vis[n] = vid;
    for (int i = grf.head[n]; ~i; i = grf.nxt[i])
    {
        if (grf.to[i] == p || vis[grf.to[i]])
        {
            continue;
        }
        dfs(grf.to[i], n, vid + 1);
    }
    for (int i = grf.head[n]; ~i; i = grf.nxt[i])
    {
        assert(vis[grf.to[i]]);
        if (grf.to[i] == p)
        {
            continue;
        }
        if (vis[grf.to[i]] < vis[n])
        {
            // cout << n << " " << p << " " << vid << " " << grf.to[i] << endl;
            cyc[n] = cyc[grf.to[i]];
            vis[n] = vis[grf.to[i]];
            blk[n] = blk[grf.to[i]] = true;
        }
    }
    // cout << cyc[n] << endl;
}

void comp(int n = 0)
{
    for (int i = grf.head[n]; ~i; i = grf.nxt[i])
    {
        if (cyc[n] == cyc[grf.to[i]] || dne[grf.to[i]])
        {
            continue;
        }
        sqz.addBiEdge(cyc[n], cyc[grf.to[i]]);
    }
    dne[n] = true;
    for (int i = grf.head[n]; ~i; i = grf.nxt[i])
    {
        if (dne[grf.to[i]])
        {
            continue;
        }
        comp(grf.to[i]);
    }
}

void dfs_tree(int n = 0, int p = -1, int lid = 0)
{
    lvl[n] = lid;
    anc[n][0] = p;
    for (int i = sqz.head[n]; ~i; i = sqz.nxt[i])
    {
        if (sqz.to[i] == p)
        {
            continue;
        }
        dfs_tree(sqz.to[i], n, lid + 1);
    }
}

int get_lca(int v, int w)
{
    if (lvl[v] < lvl[w])
    {
        swap(v, w);
    }
    // cout << lvl[v] << " " << lvl[w] << endl;
    for (int i = L - 1; ~i && lvl[v] > lvl[w]; i--)
    {
        if (~anc[v][i] && lvl[anc[v][i]] >= lvl[w])
        {
            v = anc[v][i];
        }
    }
    if (v == w)
    {
        return v;
    }
    for (int i = L - 1; ~i; i--)
    {
        if (~anc[v][i] && anc[v][i] != anc[w][i])
        {
            v = anc[v][i];
            w = anc[w][i];
        }
    }
    assert(anc[v][0] == anc[w][0]);
    return anc[v][0];
}

ll my_pow(ll a, ll p)
{
    ll ret = 1;
    while (p)
    {
        if (p & 1)
        {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        p >>= 1;
    }
    return ret;
}
void calc(int n = 0, int p = -1)
{
    clc[n] = blk[n] + (~p ? clc[p] : 0);
    for (int i = sqz.head[n]; ~i; i = sqz.nxt[i])
    {
        if (sqz.to[i] == p)
        {
            continue;
        }
        calc(sqz.to[i], n);
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    grf.init(n);
    for (int i = 0, v, w; i < m; i++)
    {
        cin >> v >> w;
        grf.addBiEdge(--v, --w);
        cyc[v] = v;
        cyc[w] = w;
    }
    dfs();
    int nn = asd(n);
    sqz.init(nn);
    comp();
    dfs_tree();
    for (int i = 1; i < L; i++)
    {
        for (int j = 0; j < nn; j++)
        {
            anc[j][i] = ~anc[j][i - 1] ? anc[anc[j][i - 1]][i - 1] : -1;
        }
    }
    calc();
    int k;
    cin >> k;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        x = cyc[x];
        y = cyc[y];
        int z = get_lca(x, y);
        cout << my_pow(2, clc[x] + clc[y] - 2 * clc[z] + blk[z]) << endl;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

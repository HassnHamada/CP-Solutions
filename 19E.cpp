#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e4 + 10, M = 2e4 + 10, L = 20;
// vector<int> tre[N];
int col[N], lvl[N], per[N][L];
vector<pair<int, int>> lop;
set<int> rem;

struct ADJ
{
    int n, head[N], nxt[M], to[M], ne;

    void addEdge(int f, int t)
    {
        nxt[ne] = head[f];
        to[ne] = t;
        head[f] = ne++;
    }

    void addBiEdge(int f, int t)
    {
        addEdge(f, t);
        addEdge(t, f);
    }

    void init(int sz)
    {
        this->n = sz;
        memset(head, -1, (this->n) * sizeof head[0]);
        ne = 0;
    }

} grf, tre;

bool bi(int n, int p = -1, int c = 1)
{
    // vis[n] = true;
    col[n] = c;
    for (int i = grf.head[n]; ~i; i = grf.nxt[i])
    {
        if (grf.to[i] == p)
        {
            continue;
        }
        if (~col[grf.to[i]] ? col[grf.to[i]] == c : !bi(grf.to[i], n, c ^ 1))
        {
            return false;
        }
    }
    return true;
}

void dfs(int n, int p = -1, int lid = 1)
{
    // cout << n << " " << p << " " << lid << endl;
    lvl[n] = lid;
    per[n][0] = p;
    for (int i = grf.head[n]; ~i; i = grf.nxt[i])
    {
        // cout << i << " " << grf.to[i] << endl;
        if (grf.to[i] == p)
        {
            continue;
        }
        if (lvl[grf.to[i]])
        {
            // cout << "HI\n";
            if (lvl[grf.to[i]] < lid)
            {
                lop.push_back({n, grf.to[i]});
            }
        }
        else
        {
            // cout << "HI too\n";
            dfs(grf.to[i], n, lid + 1);
        }
    }
}

int lca(int a, int b)
{
    if (lvl[b] > lvl[a])
    {
        swap(a, b);
    }
    for (int i = L - 1; ~i && lvl[a] > lvl[b]; i--)
    {
        if (per[a][i] == -1 || lvl[per[a][i]] < lvl[b])
        {
            continue;
        }
        a = per[a][i];
    }
    assert(lvl[a] == lvl[b]);
    if (a == b)
    {
        return a;
    }
    for (int i = L - 1; ~i; i--)
    {
        if (per[a][i] == per[b][i])
        {
            continue;
        }
        a = per[a][i];
        b = per[b][i];
    }
    return per[a][0] == per[b][0] ? per[a][0] : -1;
}

void add(int f, int t, set<int> &ret)
{
    // cout << f << " " << t << endl;
    if (f == t)
    {
        return;
    }
    for (int i = grf.head[f]; ~i; i = grf.nxt[i])
    {
        if (grf.to[i] == per[f][0])
        {
            ret.insert(i / 2);
            add(grf.to[i], t, ret);
            return;
        }
    }
}

int get(int f, int t)
{
    for (int i = grf.head[f]; ~i; i = grf.nxt[i])
    {
        if (grf.to[i] == t)
        {
            return i / 2;
        }
    }
    assert(false);
    return -1;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(col, -1, sizeof(col));
    memset(per, -1, sizeof(per));
    // memset(lvl, -1, sizeof(lvl));
    int n, m;
    cin >> n >> m;
    grf.init(n);
    for (int i = 0, v, w; i < m; i++)
    {
        cin >> v >> w;
        grf.addBiEdge(--v, --w);
    }
    bool isBi = true;
    for (int i = 0; i < n; i++)
    {
        if (col[i] == -1)
        {
            isBi &= bi(i);
        }
    }
    if (isBi)
    {
        cout << m << endl;
        for (int i = 0; i < m; i++)
        {
            cout << i + 1 << (i + 1 == n ? '\n' : ' ');
        }
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (lvl[i])
        {
            continue;
        }
        dfs(i);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << per[i][0] << endl;
    // }
    for (int i = 1; i < L; i++)
    {
        for (int j = 0; j < n; j++)
        {
            per[j][i] = per[j][i - 1] == -1 ? -1 : per[per[j][i - 1]][i - 1];
        }
    }

    bool ok = true;
    for (auto &&i : lop)
    {
        int p = lca(i.first, i.second);
        if ((lvl[i.first] - lvl[p] + lvl[i.second] - lvl[p]) % 2)
        {
            continue;
        }
        // cout << i.first << " " << i.second << " " << p << endl;
        set<int> ret;
        add(i.first, p, ret);
        add(i.second, p, ret);
        if (ok)
        {
            ret.insert(get(i.first, i.second));
        }
        else
        {
            ret.erase(get(i.first, i.second));
        }
        if (ok)
        {
            swap(rem, ret);
        }
        else
        {
            for (auto j = rem.begin(); j != rem.end();)
            {
                if (ret.find(*j) == ret.end())
                {
                    auto k = j;
                    j++;
                    rem.erase(k);
                    continue;
                }
                j++;
            }
        }
        ok = false;
        // for (auto &&j : rem)
        // {
        //     cout << j << endl;
        // }
    }
    cout << rem.size() << endl;
    for (auto &&i : rem)
    {
        cout << i + 1 << " ";
    }
    cout << endl;

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

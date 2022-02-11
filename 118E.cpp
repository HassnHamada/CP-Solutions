#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e5 + 10, M = 6e5 + 10;
vector<int> tre[N];
int vis[N], dp[N];

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

    int addNode()
    {
        head[n] = -1;
        return n++;
    }

    void init(int sz)
    {
        this->n = sz;
        memset(head, -1, (this->n) * sizeof head[0]);
        ne = 0;
    }

    void del(int e)
    {
    }
} grf;

void dfs(int n, int p = -1, int vid = 1)
{
    vis[n] = vid;
    for (int i = grf.head[n]; ~i; i = grf.nxt[i])
    {
        if (grf.to[i] == p)
        {
            continue;
        }
        if (vis[grf.to[i]])
        {
            dp[n] += (vis[grf.to[i]] > vid ? -1 : 1);
            continue;
        }
        dfs(grf.to[i], n, vid + 1);
        dp[n] += dp[grf.to[i]];
    }
    // cout << n << " " << dp[n] << endl;
}

void prn(int n, int p = -1, int vid = 1)
{
    for (int i = grf.head[n]; ~i; i = grf.nxt[i])
    {
        if (grf.to[i] == p || vis[grf.to[i]] < vid)
        {
            continue;
        }
        if (vis[grf.to[i]] == vid + 1)
        {
            cout << n + 1 << " " << grf.to[i] + 1 << endl;
            prn(grf.to[i], n, vid + 1);
        }
        else
        {
            cout << grf.to[i] + 1 << " " << n + 1 << endl;
        }
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
    }
    dfs(0);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << dp[i] << endl;
    // }

    if (any_of(dp + 1, dp + n, [](int i)
               { return i == 0; }))
    {
        cout << 0 << endl;
    }
    else
    {
        prn(0);
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

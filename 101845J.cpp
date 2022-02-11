#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 510, M = 510;
int vis[N], dis[N], cst[N], vid;

struct Route
{
    int u, v, t, c, f, s;
    int to(int n)
    {
        return n == u ? v : u;
    }
    int lt(int st)
    {
        return f - (st - s + f) % f;
    }
};

struct Station
{
    int t, c, s;
    bool operator<(const Station &other) const
    {
        return this->t == other.t ? this->c > other.c : this->t > other.t;
    }
};

struct Graph
{
    int head[N], nxt[M], ei;
    Route pth[M];
    void init(int n)
    {
        memset(head, -1, n * sizeof(head[0]));
        ei = 0;
    }
    void addEdge(int u, int v, int t, int c, int f, int s)
    {
        nxt[ei] = head[u];
        pth[ei] = {u, v, t, c, f, s};
        head[u] = ei++;
    }
} grf;

void dijkstra()
{
    dis[1] = cst[1] = 0;
    priority_queue<Station> pq;
    pq.push({0, 0, 1});
    while (!pq.empty())
    {
        auto c = pq.top();
        pq.pop();
        if (c.t != dis[c.s] || c.c != cst[c.s])
        {
            continue;
        }
        vis[c.s] = vid;
        for (int i = grf.head[c.s]; ~i; i = grf.nxt[i])
        {
            int t = grf.pth[i].to(c.s);
            if (vis[t] == vid)
            {
                continue;
            }
            int cd = c.t + grf.pth[i].lt(c.t) + grf.pth[i].t,
                cc = c.c + grf.pth[i].c;
            if (cd < dis[t] || (cd == dis[t] && cc < cst[t]))
            {
                dis[t] = cd;
                cst[t] = cc;
                pq.push({cd, cc, t});
            }
        }
    }
}

void run()
{
    int n, m;
    cin >> n >> m;
    grf.init(n + 1);
    memset(dis, 0x7f, (n + 1) * sizeof(dis[0]));
    memset(cst, 0x7f, (n + 1) * sizeof(cst[0]));
    for (int i = 0, u, v, t, c, f, s; i < m; i++)
    {
        cin >> u >> v >> t >> c >> f >> s;
        grf.addEdge(u, v, t, c, f, s);
    }
    dijkstra();
    cout << dis[n] << " " << cst[n] << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    // while (t--)
    while (vid++ < t)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int vis[N], dis[2][N], low[N], id[N], vid, nid;
bool stk[N];

struct Edge
{
    int u, v, w;
    int to(int n)
    {
        return n == u ? v : u;
    }
};

struct Graph
{
    int head[N], nxt[M], ei;
    Edge edg[M];
    void init(int n)
    {
        memset(head, -1, n * sizeof(head[0]));
        ei = 0;
    }
    void addEdge(int u, int v, int w)
    {
        nxt[ei] = head[u];
        edg[ei] = {u, v, w};
        head[u] = ei++;
    }

    void addBiEdge(int u, int v, int w)
    {
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    void prn(bool bi)
    {
        for (int i = 0; i < ei; i += 1 + bi)
        {
            cout << edg[i].u << " " << edg[i].v << " " << edg[i].w << endl;
        }
    }
} grf, grf2;

void dijkstra(int s, int p)
{
    dis[p][s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto c = pq.top();
        pq.pop();
        if (c.first != dis[p][c.second])
        {
            continue;
        }
        vis[c.second] = vid;
        for (int i = grf.head[c.second]; ~i; i = grf.nxt[i])
        {
            int t = grf.edg[i].to(c.second), w = c.first + grf.edg[i].w;
            if (vis[t] == vid || w >= dis[p][t])
            {
                continue;
            }
            dis[p][t] = w;
            pq.push({w, t});
        }
    }
}

bool tarjan(int n, int p)
{
    id[n] = low[n] = ++nid;
    for (int i = grf2.head[n]; ~i; i = grf2.nxt[i])
    {
        int t = grf2.edg[i].to(n);
        if (t == p)
        {
            continue;
        }
        if (id[t])
        {
            // continue;
            low[n] = min(low[n], low[t]);
        }
        else
        {
            if (tarjan(t, n))
            {
                return true;
            }
            low[n] = min(low[n], low[t]);
            if (low[t] > id[n] && !stk[n] && stk[t])
            {
                return true;
            }
            stk[n] |= stk[t];
        }
    }
    return false;
}

bool ok(int m, int s, int n, int t)
{

    grf2.init(n);
    memset(low, 0, n * sizeof(low[0]));
    memset(id, 0, n * sizeof(id[0]));
    memset(stk, 0, n * sizeof(stk[0]));
    nid = 0;
    stk[t] = true;
    for (int i = 0; i < grf.ei; i += 2)
    {
        int u = grf.edg[i].u, v = grf.edg[i].v, w = grf.edg[i].w;
        if (min(dis[0][u] + dis[1][v], dis[0][v] + dis[1][u]) + w <= m)
        {
            // cout << i << endl;
            grf2.addBiEdge(u, v, w);
        }
    }
    // grf2.prn(1);
    return tarjan(s, -1);
}

void run()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    grf.init(n);
    memset(dis, 0x3f, n * sizeof(dis[0][0]));
    memset(dis + 1, 0x3f, n * sizeof(dis[0][0]));
    // cout << vid << endl;
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        grf.addBiEdge(--u, --v, w);
    }
    dijkstra(--s, vid++);
    dijkstra(--t, vid++);
    // cout << ok(4, s, n, t) << endl;
    int l = dis[0][t], h = INF;
    while (l < h)
    {
        int mid = l + (h - l) / 2;
        if (ok(mid, s, n, t))
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    cout << (h == INF ? -1 : h) << endl;
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
    while (t--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

//  1 0 0   0 1 0   0 0 1
//  0 1 1   1 0 1   1 1 0
//  2 1 1   1 2 1   1 1 2
//  2 3 3   3 2 3   3 3 2
//  6 5 5   5 6 5   5 5 6

#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
int vis[N], dis[N], vid;

struct Edge
{
    int u, v, w;
    bitset<1000> bs;
    int to(int n)
    {
        return n == u ? v : u;
    }
    void add(int at)
    {
        assert(at > 0 && at < w);
        bs.set(at);
    }
    // bool operator==(const Edge &other) const
    // {
    //     return other.u == v && other.v == u && other.w == w;
    // }
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
    int count()
    {
        int ret = 0;
        for (int i = 0; i < ei; i += 2)
        {
            ret += edg[i].bs.count();
        }
        return ret;
    }
} grf;

void dijkstra(int s)
{
    // int ret = 0;
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto c = pq.top();
        pq.pop();
        if (c.first != dis[c.second])
        {
            continue;
        }
        vis[c.second] = vid;
        // ret += (c.first == l);
        for (int i = grf.head[c.second]; ~i; i = grf.nxt[i])
        {
            int t = grf.edg[i].to(c.second), w = c.first + grf.edg[i].w;
            // if (c.first < l && w > l && (!vis[t] || dis[t] + grf.edg[i].w - l + c.first > c.first + l - c.first))
            // {
            //     grf.edg[i].add(l - c.first);
            //     assert(grf.edg[i] == grf.edg[i ^ 1]);
            //     grf.edg[i ^ 1].add(grf.edg[i].w - l + c.first);
            // }
            if (vis[t] == vid || w >= dis[t])
            {
                continue;
            }
            dis[t] = w;
            pq.push({w, t});
        }
    }
    // cout << ret << endl;
    // return ret + grf.count();
}

void run()
{
    int n, m, s;
    cin >> n >> m >> s;
    grf.init(n);
    memset(dis, 0x3f, n * sizeof(dis[0]));
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        grf.addBiEdge(--u, --v, w);
    }
    int l;
    cin >> l;
    vid++;
    dijkstra(--s);
    for (int i = 0; i < grf.ei; i += 2)
    {
        int u = grf.edg[i].u, v = grf.edg[i].v, w = grf.edg[i].w;
        if (dis[u] < l && dis[v] < l && dis[u] + dis[v] + w == 2 * l)
        {
            // cout << i << " 1\n";
            grf.edg[i].add(l - dis[u]);
            grf.edg[i].add(w - l + dis[v]);
        }
        if (dis[u] < l && l - dis[u] < w && w - (l - dis[u]) + dis[v] > l)
        {
            // cout << i << " 2\n";
            grf.edg[i].add(l - dis[u]);
        }
        if (dis[v] < l && l - dis[v] < w && w - (l - dis[v]) + dis[u] > l)
        {
            // cout << i << " 3\n";
            grf.edg[i].add(w - l + dis[v]);
        }
        // cout << grf.count() << endl;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (dis[i] == l);
    }
    cout << ans + grf.count() << endl;
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

#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 3e4 + 10, M = 1e5 + 10;
ll vis[N], head[N], nxt[M], to[M], cst[M], dis[N], pine[N], ei, vid;

void addEdge(int u, int v, int c)
{
    nxt[ei] = head[u];
    to[ei] = v;
    cst[ei] = c;
    head[u] = ei++;
}

void addBiEdge(int u, int v, int c)
{
    addEdge(u, v, c);
    addEdge(v, u, c);
}

void dijkstra()
{
    dis[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto c = pq.top();
        pq.pop();
        if (c.first != dis[c.second])
        {
            continue;
        }
        // cout << c.second << " " << c.first << endl;
        vis[c.second] = vid;
        for (int i = head[c.second]; ~i; i = nxt[i])
        {
            if (vis[to[i]] == vid)
            {
                continue;
            }
            ll t = pine[c.second] + c.first + cst[i];
            // cout << to[i] << " " << cst[i] << endl;
            if (t < dis[to[i]])
            {
                dis[to[i]] = t;
                pq.push({dis[to[i]], to[i]});
            }
        }
    }
}

void run()
{
    ll n, m, t, k, p;
    cin >> n >> m >> t >> k >> p;
    memset(head, -1, (n + 1) * sizeof(head[0]));
    memset(dis, 0x7f, (n + 1) * sizeof(dis[0]));
    // cout << t * 60 << " " << dis[n] << endl;
    ei = 0;
    for (int i = 0, v; i < p; i++)
    {
        cin >> v;
        pine[v] = k;
    }
    for (int i = 1, a, b, c; i <= m; i++)
    {
        cin >> a >> b >> c;
        addEdge(a, b, c * 60);
    }
    // cout << (t * 60 > dis[n] ? -1 : dis[n]) << endl;
    dijkstra();
    cout << (t * 60 < dis[n] ? -1 : dis[n]) << endl;
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

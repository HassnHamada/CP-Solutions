#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e2 + 10, M = 1 << 12, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

vector<pair<int, int>> grf[N];
int dis[N];

void dijkstra(int s, int x)
{
    set<pair<int, int>> pq;
    pq.insert({dis[s] = x, s});
    while (!pq.empty())
    {
        auto [w, u] = *pq.begin();
        pq.erase(pq.begin());
        assert(dis[u] == w);
        for (auto &&[i, j] : grf[u])
        {
            if (dis[i] > w + j + x)
            {
                pq.erase({dis[i], i});
                pq.insert({dis[i] = w + j + x, i});
            }
        }
    }
}

void run()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1, u, v, w; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        grf[u].emplace_back(v, w);
    }
    for (int i = 1, u, v, x; i <= q; i++)
    {
        scanf("%d%d%d", &u, &v, &x);
        memset(dis, 0x3f, sizeof(dis[0]) * (n + 1));
        dijkstra(u, x);
        printf("%d\n", dis[v] == INF ? -1 : dis[v]);
    }
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
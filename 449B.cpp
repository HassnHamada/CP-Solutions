#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

struct DT
{
    ll cost;
    int to, train;
    bool operator<(const DT &other) const
    {
        return cost < other.cost;
    }
    bool operator>(const DT &other) const
    {
        return cost > other.cost;
    }
} dis[N];
vector<DT> grf[N];
bool don[N];

void run()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        grf[u].push_back({x, v, -1});
        grf[v].push_back({x, u, -1});
    }
    for (int i = 0; i < k; i++)
    {
        int s, y;
        scanf("%d%d", &s, &y);
        grf[1].push_back({y, s, i});
        grf[s].push_back({y, 1, i});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = {1ll * INF * INF, -1, -1};
    }
    priority_queue<DT, vector<DT>, greater<DT>> pq;
    pq.push({0ll, 1, -1});
    while (!pq.empty())
    {

        auto [cost, to, train] = pq.top();
        pq.pop();
        if (dis[to].cost <= cost)
        {
            if (dis[to].cost == cost && train == -1)
            {
                dis[to].train = train;
            }
            continue;
        }
        don[to] = true;
        dis[to] = {cost, -1, train};
        for (auto &&[_cost, _to, _train] : grf[to])
        {
            if (don[_to])
            {
                assert(dis[_to].cost <= _cost + cost);
                if (dis[_to].cost == _cost + cost && _train == -1)
                {
                    dis[_to].train = _train;
                }
                continue;
            }
            pq.push({_cost + cost, _to, _train});
        }
    }
    set<int> usd;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i].train == -1)
        {
            continue;
        }
        usd.insert(dis[i].train);
        // fprintf(stderr, "%d %lld %d\n", i, dis[i].cost, dis[i].train);
    }
    printf("%d\n", k - (int)usd.size());
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
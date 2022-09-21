#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int n, m, k;
ll dis[N][M];
vector<pair<int, int>> adj[N];

void run()
{
    memset(dis, 0x0f, sizeof(dis));
    dis[1][0] = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        ll a = pq.top().first, b = pq.top().second;
        pq.pop();
        if (dis[b][k - 1] < a)
        {
            continue;
        }
        for (pair<int, int> i : adj[b])
        {
            ll c = i.first, d = i.second;
            if (dis[c][k - 1] <= a + d)
            {
                continue;
            }
            dis[c][k - 1] = a + d;
            pq.push({a + d, c});
            sort((ll *)(dis + c), (ll *)(dis + c) + k);
        }
    }

    for (int i = 0; i < k; i++)
    {
        printf("%lld%c", dis[n][i], " \n"[i + 1 == k]);
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
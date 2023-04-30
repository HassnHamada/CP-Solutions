#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int vis[N], vid, aaa[N], bbb[N], ccc[N];
ll cst[N];
vector<int> grf[N];

void bfs(int s, int *dis)
{
    queue<int> q;
    q.push(s);
    vis[s] = ++vid;
    dis[s] = 0;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (auto &&i : grf[f])
        {
            if (vis[i] == vid)
            {
                continue;
            }
            vis[i] = vid;
            dis[i] = dis[f] + 1;
            q.push(i);
        }
    }
}

void run()
{
    int n, m, a, b, c;
    scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", cst + i);
    }
    sort(cst, cst + m + 1);
    for (int i = 1; i <= m; i++)
    {
        cst[i] += cst[i - 1];
    }
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u].push_back(v);
        grf[v].push_back(u);
    }
    bfs(a, aaa);
    assert(all_of(vis + 1, vis + n + 1, [](int i)
                  { return i == vid; }));

    bfs(b, bbb);
    assert(all_of(vis + 1, vis + n + 1, [](int i)
                  { return i == vid; }));
    bfs(c, ccc);
    assert(all_of(vis + 1, vis + n + 1, [](int i)
                  { return i == vid; }));
    ll ans = INT64_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (aaa[i] + bbb[i] + ccc[i] > m)
        {
            continue;
        }
        ans = min(ans, cst[bbb[i]] + cst[aaa[i] + bbb[i] + ccc[i]]);
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++)
    {
        grf[i].clear();
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
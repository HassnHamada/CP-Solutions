#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<pair<int, int>> grf[N], grf_2[N];
ll ans[N];
bool vis[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v, w; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        grf[u].emplace_back(v, w);
        grf_2[v].emplace_back(u, w);
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    memset(ans, 0x3f, sizeof(ans));
    pq.emplace(ans[1] = 0, 1);
    while (!pq.empty())
    {
        pair<ll, int> v = pq.top();
        pq.pop();
        assert(v.first >= ans[v.second]);
        if (v.first != ans[v.second])
        {
            continue;
        }
        for (auto &&i : grf[v.second])
        {
            if (i.second + v.first < ans[i.first])
            {
                ans[i.first] = i.second + v.first;
                pq.emplace(ans[i.first], i.first);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        pq.emplace(ans[i], i);
    }
    while (!pq.empty())
    {
        pair<ll, int> v = pq.top();
        pq.pop();
        assert(v.first >= ans[v.second]);
        if (v.first != ans[v.second])
        {
            continue;
        }
        for (auto &&i : grf_2[v.second])
        {
            if (i.second + v.first < ans[i.first])
            {
                ans[i.first] = v.first + i.second;
                pq.emplace(ans[i.first], i.first);
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (ans[i] == 0x3f3f3f3f3f3f3f3f)
        {
            ans[i] = -1;
        }
        printf("%lld%c", ans[i], " \n"[i == n]);
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
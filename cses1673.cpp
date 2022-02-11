#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
typedef long long int ll;

const int N = 5e3 + 10;
struct Edge
{
    int s, d, w = INT32_MAX;
} edg[N];
ll dst[N], n, m;
vector<int> grf[N];
bool vis[N], rch[N];

bool BellmanFord(int src)
{
    for (int i = 1; i <= n; i++)
    {
        dst[i] = INT64_MAX;
    }
    dst[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int s = edg[j].s, d = edg[j].d, w = edg[j].w;
            // cout << s << " " << d << " " << w << endl;
            if (dst[s] != INT64_MAX && dst[s] + w < dst[d])
            {
                dst[d] = dst[s] + w;
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dst[i] << " \n"[i == n];
    // }
    for (int j = 0; j < m; j++)
    {
        int s = edg[j].s, d = edg[j].d, w = edg[j].w;
        if (dst[s] != INT64_MAX && dst[s] + w < dst[d] && rch[d])
        {
            return false;
        }
    }
    return true;
}

bool dfs(int s, int t)
{
    if (s == t)
    {
        rch[s] = true;
        return true;
    }
    vis[s] = true;
    for (auto &&i : grf[s])
    {
        if (vis[i])
        {
            continue;
        }
        if (dfs(i, t))
        {
            vis[s] = false;
            rch[s] = true;
            return true;
        }
    }
    vis[s] = false;
    return false;
}

void run()
{
    cin >> n >> m;
    for (int i = 0, x; i < m; i++)
    {
        cin >> edg[i].s >> edg[i].d >> x;
        edg[i].w = min(edg[i].w, -x);
        grf[edg[i].s].push_back(edg[i].d);
        // cout << edg[i].d << endl;
    }
    for (int i = 1; i < n; i++)
    {
        if (rch[i])
        {
            continue;
        }
        dfs(i, n);
    }

    cout << (BellmanFord(1) ? -dst[n] : -1ll) << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << ans[i] << " \n"[i == n];
    // }
}

int main(int argc, char const *argv[])
{
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(6) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}
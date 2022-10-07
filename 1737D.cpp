#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e2 + 10, M = 3e5, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N];

struct Edge
{
    ll u, v, w;
} edg[M];

int vis[N], vid;

ll dfs(int c, int t, ll r, bool s)
{
    if (c == t)
    {
        return r;
    }
    vis[c] = vid;
    ll ret = -1;
    for (auto &&idx : grf[c])
    {
        auto [u, v, w] = edg[idx];
        if (u == c)
        {
            swap(u, v);
        }
        if (vis[u] == vid)
        {
            continue;
        }
        if (s)
        {
            ll res = dfs(u, t, r, false);
            if (res == -1)
            {
                continue;
            }
            if (ret == -1)
            {
                ret = res;
            }
            else
            {
                ret = min(ret, res);
            }
        }
        else
        {
            ll res_1 = dfs(u, t, r + w, false),
               res_2 = dfs(u, t, r + 2 * w, true);
            if (res_1 == -1 && res_2 == -1)
            {
                continue;
            }
            if (res_1 == -1 || res_2 == -1)
            {
                if (res_1 == -1)
                {
                    swap(res_1, res_2);
                }
                if (ret == -1)
                {
                    ret = res_1;
                }
                else
                {
                    ret = min(ret, res_1);
                }
            }
            else
            {
                if (ret == -1)
                {
                    ret = min(res_1, res_2);
                }
                else
                {
                    ret = min({ret, res_1, res_2});
                }
            }
        }
    }
    return ret;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld", &edg[i].u, &edg[i].v, &edg[i].w);
        grf[edg[i].u].push_back(i);
        grf[edg[i].v].push_back(i);
    }
    vid++;
    printf("%lld\n", dfs(1, n, 0, false));
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
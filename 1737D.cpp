#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e2 + 10, M = 3e5, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N];
int cst[N][N], dis[N][N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(cst, 0x3f, sizeof(cst));
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 0; i < N; i++)
    {
        grf[i].clear();
        dis[i][i] = 0;
    }
    for (int i = 0, u, v, w; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        grf[--u].push_back(--v);
        grf[v].push_back(u);
        // assert(cst[u][v] == cst[v][u]);
        // assert(dis[u][v] == dis[v][u]);
        cst[u][v] = cst[v][u] = min(cst[u][v], w);
        dis[u][v] = dis[v][u] = 1;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         assert(dis[i][j] != INF);
    //     }
    // }

    ll ans = INT64_MAX;
    for (int i = 0; i < n; i++)
    {
        for (auto &&j : grf[i])
        {
            assert(cst[i][j] < INF);
            ans = min(ans, (min(dis[i][0] + dis[j][n - 1], dis[i][n - 1] + dis[j][0]) + 1ll) * cst[i][j]);
            for (int k = 0; k < n; k++)
            {
                ans = min(ans, (min(dis[i][k], dis[j][k]) + dis[k][n - 1] + dis[k][0] + 2ll) * cst[i][j]);
            }
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
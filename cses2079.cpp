#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 14, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

map<int, int> sz[N];
vector<int> tre[N];

void dfs(int n, int p)
{
    if (sz[n].find(p) == sz[n].end())
    {
        sz[n][p] = 1;
        for (auto &&i : tre[n])
        {
            if (i == p)
            {
                continue;
            }
            dfs(i, n);
            sz[n][p] += sz[i][n];
        }
    }
}

int ans(int n)
{
    for (int i = 1; i <= n; i++)
    {
        bool ok = true;
        for (auto &&j : tre[i])
        {
            assert(sz[j].find(i) != sz[j].end());
            if (sz[j][i] > n / 2)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            return i;
        }
    }
    assert(false);
    return -1;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, 0);
    }
    printf("%d\n", ans(n));
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
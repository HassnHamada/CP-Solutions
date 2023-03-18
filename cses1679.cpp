#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 20, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

bool don[N], vis[N];
vector<int> grf[N], ans;

bool dfs(int n)
{
    vis[n] = true;
    for (auto &&i : grf[n])
    {
        assert(!don[i] || !vis[i]);
        if (don[i])
        {
            continue;
        }
        if (vis[i] || !dfs(i))
        {
            return false;
        }
    }
    don[n] = true;
    vis[n] = false;
    ans.push_back(n);
    return true;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u].push_back(v);
    }
    bool ok = true;
    for (int i = 1; ok && i <= n; i++)
    {
        if (don[i])
        {
            continue;
        }
        ok = dfs(i);
    }
    if (ok)
    {
        reverse(ans.begin(), ans.end());
        for (auto &&i : ans)
        {
            printf("%d%c", i, " \n"[i == *ans.rbegin()]);
        }
    }
    else
    {
        printf("IMPOSSIBLE\n");
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
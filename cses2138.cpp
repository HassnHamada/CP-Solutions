#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

const int N = 5e4 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

bitset<N> ans[N];
vector<int> tre[N];

void dfs(int n)
{
    ans[n][n] = 1;
    for (auto &&i : tre[n])
    {
        if (ans[i][i] == 0)
        {
            dfs(i);
        }
        ans[n] |= ans[i];
    }
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        tre[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i][i])
        {
            continue;
        }
        dfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d%c", (int)ans[i].count(), " \n"[i == n]);
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
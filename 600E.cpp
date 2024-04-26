#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int col[N];
map<int, ll> ans[N];
vector<int> adj[N];

void dfs(int n, int p, map<int, int> &out)
{
    out[col[n]]++;
    ans[n][1] = col[n];
    for (auto &&i : adj[n])
    {
        if (i == p)
        {
            continue;
        }
        map<int, int> res;
        dfs(i, n, res);
        if (res.size() > out.size())
        {
            auto [mx, sm] = *ans[i].rbegin();
            ans[n].clear();
            ans[n][mx] = sm;
            swap(res, out);
        }
        for (auto &&[j, k] : res)
        {
            ans[n][out[j] += k] += j;
        }
    }
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", col + i);
    }
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    map<int, int> res;
    dfs(1, 0, res);
    for (int i = 1; i <= n; i++)
    {
        printf("%lld%c", ans[i].rbegin()->second, " \n"[i == n]);
    }
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
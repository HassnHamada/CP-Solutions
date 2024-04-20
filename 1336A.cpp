#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> adj[N];
int sz[N], dep[N], ind[N];

void dfs(int n, int p = 0)
{
    for (auto &&i : adj[n])
    {
        if (i == p)
        {
            continue;
        }
        dep[i] = dep[n] + 1;
        dfs(i, n);
        sz[n] += sz[i] + 1;
    }
}


void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    iota(ind + 1, ind + n + 1, 1);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    sort(ind + 1, ind + n + 1, [&](int a, int b)
         { return dep[a] - sz[a] > dep[b] - sz[b]; });
    ll ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += dep[ind[i + 1]] - sz[ind[i + 1]];
    }
    printf("%lld\n", ans);
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
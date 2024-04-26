#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> adj[N];

int dfs(int n, int p, int k, vector<int> &out)
{
    int ret = 0;
    vector<int> tmp(k + 1);
    tmp[0] = 1;
    assert(tmp[0] == 1);
    assert((int)out.size() == k + 1);
    assert((int)tmp.size() == k + 1);
    for (auto &&i : adj[n])
    {
        if (i == p)
        {
            continue;
        }
        vector<int> res(k + 1);
        ret += dfs(i, n, k, res);
        for (int j = 0; j <= k; j++)
        {
            ret += tmp[k - j] * res[j];
        }
        for (int j = 0; j <= k; j++)
        {
            tmp[j] += res[j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        out[i + 1] = tmp[i];
    }
    return ret;
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> res(k + 1);
    int ans = dfs(1, 0, k, res);
    printf("%d\n", ans);
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
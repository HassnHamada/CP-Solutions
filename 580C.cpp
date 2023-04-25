#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];
vector<int> tre[N];

int dfs(int m, int n = 1, int p = 0, int c = 0)
{
    if (c + arr[n] > m)
    {
        return 0;
    }
    int sz = tre[n].size() - (p ? 1 : 0), ret = 0;
    if (sz == 0)
    {
        return 1;
    }
    for (auto &&i : tre[n])
    {
        if (i == p)
        {
            continue;
        }
        assert(sz--);
        ret += dfs(m, i, n, (c + arr[n]) * arr[n]);
    }
    assert(sz == 0);
    return ret;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    printf("%d\n", dfs(m));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
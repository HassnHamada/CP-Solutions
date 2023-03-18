#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int prv[N], nxt[N], sz[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v, d; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &d);
        prv[v] = u, nxt[u] = v, sz[u] = d;
    }
    vector<tuple<int, int, int>> ans;
    for (int i = 1; i <= n; i++)
    {
        if (prv[i] || !nxt[i])
        {
            continue;
        }
        int j = i, k = INF;
        while (nxt[j])
        {
            k = min(k, sz[j]);
            j = nxt[j];
        }
        ans.emplace_back(i, j, k);
    }
    sort(ans.begin(), ans.end(), [](tuple<int, int, int> t1, tuple<int, int, int> t2)
         { return get<0>(t1) < get<0>(t2); });
    printf("%d\n", (int)ans.size());
    for (auto &&[i, j, k] : ans)
    {
        printf("%d %d %d\n", i, j, k);
    }
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
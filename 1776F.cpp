#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e3 + 10, M = 1e6 + 10, Q = 548, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> ans(m, 1);
    vector<vector<int>> grf(n);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u - 1].emplace_back(i);
        grf[v - 1].emplace_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        assert(!grf[i].empty());
        assert((int)grf[i].size() < n);
    }
    int seed = 0;
    while (m != n * (n - 1) / 2 && (int)grf[seed].size() == n - 1)
    {
        seed += 1;
    }
    assert(seed < n);
    for (auto &&i : grf[seed])
    {
        ans[i] = 2;
    }
    if (m == n * (n - 1) / 2)
    {
        ans[grf[seed].back()] = 3;
        printf("3\n");
    }
    else
    {
        printf("2\n");
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == m]);
    }
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

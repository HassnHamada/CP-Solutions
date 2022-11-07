#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 448, MOD = 1e9, HV = 151, INF = 0x3f3f3f3f;

ll arr[N], frq[N], ans[N];
vector<pair<int, int>> tre[N];

void dfs(int n, int p, map<ll, ll> &col)
{
    for (auto &&[i, e] : tre[n])
    {
        if (i == p)
        {
            continue;
        }
        map<ll, ll> tem;
        dfs(i, n, tem);
        assert(ans[e] == 0);
        for (auto &&[j, k] : tem)
        {
            ans[e] += (frq[j] - k) * k;
        }
        if (tem.size() > col.size())
        {
            swap(tem, col);
        }
        for (auto &&[j, k] : tem)
        {
            col[j] += k;
        }
    }
    col[arr[n]]++;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", arr + i);
        frq[arr[i]]++;
    }
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        tre[u].emplace_back(v, i);
        tre[v].emplace_back(u, i);
    }
    map<ll, ll> col;
    dfs(1, 0, col);
    for (auto &&[i, j] : col)
    {
        assert(frq[i] == j);
    }
    for (int i = 0; i < n - 1; i++)
    {
        printf("%lld%c", ans[i], " \n"[i == n - 2]);
    }
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
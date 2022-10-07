#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e2 + 10, M = 8, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int prv[N];
map<int, ll> grf[N];

ll bfs(int e)
{
    memset(prv, -1, sizeof(prv));
    queue<tuple<int, ll>> q;
    q.emplace(0, INT64_MAX);
    while (!q.empty())
    {
        auto [n, v] = q.front();
        q.pop();
        for (auto &&[i, f] : grf[n])
        {
            if (i && prv[i] == -1 && f)
            {
                prv[i] = n;
                ll n_f = min(f, v);
                if (i == e)
                {
                    return n_f;
                }
                q.emplace(i, n_f);
            }
        }
    }
    return 0;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b, c; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        --a, --b;
        if (grf[a].find(b) == grf[a].end())
        {
            grf[a].emplace(b, 0);
            assert(grf[b].find(a) == grf[b].end());
            grf[b].emplace(a, 0);
        }
        grf[a][b] += c;
    }
    ll ans = 0;
    while (true)
    {
        ll tem = bfs(n - 1);
        if (tem == 0)
        {
            break;
        }
        ans += tem;
        int c = n - 1;
        while (c)
        {
            grf[prv[c]][c] -= tem;
            grf[c][prv[c]] += tem;
            c = prv[c];
        }
    }
    printf("%lld\n", ans);
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
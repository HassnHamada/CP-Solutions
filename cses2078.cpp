#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

vector<int> grf[N];
int lvl[N];

ll my_pow(ll b, ll p, ll m = MOD)
{
    b %= m;
    p %= (m - 1);
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = r * b % m;
        }
        p /= 2;
        b = b * b % m;
    }
    return r;
}

int dfs(int n, int p = 0)
{
    lvl[n] = lvl[p] + 1;
    int ret = 0;
    for (auto &&i : grf[n])
    {
        if (i == p)
        {
            continue;
        }
        if (lvl[i])
        {
            if (lvl[i] < lvl[n])
            {
                ret++;
            }
        }
        else
        {
            ret += dfs(i, n);
        }
    }
    return ret;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u].push_back(v);
        grf[v].push_back(u);
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!lvl[i])
        {
            ans = ans * my_pow(2, dfs(i)) % MOD;
        }
    }
    printf("%lld\n", ans);
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
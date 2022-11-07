#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 14, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> tre[N];
bool don[N];
int sz[N], cnt[N];

int calc_sz(int n, int p)
{
    assert(!don[n]);
    sz[n] = 1;
    for (auto &&i : tre[n])
    {
        if (i == p || don[i])
        {
            continue;
        }
        sz[n] += calc_sz(i, n);
    }
    return sz[n];
}

int get_cen(int n, int p, int t)
{
    for (auto &&i : tre[n])
    {
        if (i == p || don[i])
        {
            continue;
        }
        if (sz[i] >= t)
        {
            return get_cen(i, n, t);
        }
    }
    return n;
}

ll calc(int n, int p, int d, int k)
{
    if (d == k)
    {
        return 1;
    }
    ll ret = cnt[k - d];
    for (auto &&i : tre[n])
    {
        if (i == p || don[i])
        {
            continue;
        }
        ret += calc(i, n, d + 1, k);
    }
    return ret;
}

int fill_(int n, int p, int d, int k)
{
    if (d == k)
    {
        return d;
    }
    cnt[d]++;
    int ret = d;
    for (auto &&i : tre[n])
    {
        if (i == p || don[i])
        {
            continue;
        }
        ret = max(ret, fill_(i, n, d + 1, k));
    }
    return ret;
}

ll solve(int n, int k)
{
    n = get_cen(n, 0, calc_sz(n, 0) >> 1);
    don[n] = true;
    ll ans = 0;
    int d = 0;
    for (auto &&i : tre[n])
    {
        if (don[i])
        {
            continue;
        }
        ans += calc(i, n, 1, k);
        d = max(d, fill_(i, n, 1, k));
    }
    memset(cnt, 0, sizeof(cnt[0]) * (d + 1));
    for (auto &&i : tre[n])
    {
        if (don[i])
        {
            continue;
        }
        ans += solve(i, k);
    }
    return ans;
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    printf("%lld\n", solve(1, k));
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
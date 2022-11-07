#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 18, M = 14, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> tre[N];
bool don[N];
int sz[N], dep[N], n, kl, kh, cnt[N + 1];

int calc_sz(int cn, int pn = 0)
{
    assert(!don[cn]);
    dep[cn] = sz[cn] = 1;
    for (auto &&i : tre[cn])
    {
        if (i == pn || don[i])
        {
            continue;
        }
        sz[cn] += calc_sz(i, cn);
        dep[cn] = max(dep[cn], dep[i] + 1);
    }
    return sz[cn];
}

int get_cen(int t, int cn, int cp = 0)
{
    assert(!don[cn]);
    for (auto &&i : tre[cn])
    {
        if (i == cp || don[i])
        {
            continue;
        }
        if (sz[i] >= t)
        {
            return get_cen(t, i, cn);
        }
    }
    return cn;
}

void add(int i, int v, int mx)
{
    for (i++; i <= mx; i += i & (-i))
    {
        cnt[i - 1] += v;
    }
}

ll get(int i)
{
    ll ret = 0;
    for (i++; i; i -= i & (-i))
    {
        ret += cnt[i - 1];
    }
    return ret;
}

ll calc(int mx, int cn, int cp = 0, int d = 1)
{
    if (d > kh)
    {
        return 0;
    }
    ll ret = (kh - d >= mx ? get(mx - 1) : get(kh - d)) - (kl - 1 - d >= 0 ? (kl - 1 - d >= mx ? get(mx - 1) : get(kl - 1 - d)) : 0);
    assert(ret >= 0);
    for (auto &&i : tre[cn])
    {
        if (i == cp || don[i])
        {
            continue;
        }
        ret += calc(mx, i, cn, d + 1);
    }
    return ret;
}

void fill(int mx, int cn, int cp = 0, int d = 1)
{
    assert(d < mx);
    add(d, 1, mx);
    for (auto &&i : tre[cn])
    {
        if (i == cp || don[i])
        {
            continue;
        }
        fill(mx, i, cn, d + 1);
    }
}

ll solve(int cn = 1)
{
    cn = get_cen(calc_sz(cn) >> 1, cn);
    calc_sz(cn);
    don[cn] = true;
    ll ans = 0;
    int d = (int)ceil(log2(dep[cn] + 1));
    d = 1 << d;
    assert(d <= N);
    add(0, 1, d);
    for (auto &&i : tre[cn])
    {
        if (don[i])
        {
            continue;
        }
        ans += calc(d, i);
        fill(d, i);
    }
    assert(cnt[d] == 0);
    memset(cnt, 0, sizeof(cnt[0]) * d);
    for (auto &&i : tre[cn])
    {
        if (don[i])
        {
            continue;
        }
        ans += solve(i);
    }
    return ans;
}

void run()
{
    scanf("%d%d%d", &n, &kl, &kh);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    printf("%lld\n", solve());
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
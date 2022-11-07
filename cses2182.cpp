#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 17, M = 14, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

pair<int, int> inp[N];

ll my_pow(ll b, ll p, ll m = MOD)
{
    b = b % m;
    p = p % (m - 1);
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = r * b % m;
        }
        p = p >> 1;
        b = b * b % m;
    }
    return r;
}

ll inv(ll b, ll m = MOD)
{
    return my_pow(b, m - 2, m);
}

ll g_sum(ll a, ll r, ll n)
{
    assert(r != 1);
    return a * ((my_pow(r, n) - 1 + MOD) % MOD) % MOD * inv(r - 1) % MOD;
}

int seg[N << 1];

void build(int i, int s, int e)
{
    if (s == e)
    {
        seg[i] = (inp[s].second + 1) % (MOD - 1);
        return;
    }
    int l = 2 * i + 1, r = l + 1, m = (e + s) / 2;
    build(l, s, m);
    build(r, m + 1, e);
    seg[i] = 1ll * seg[l] * seg[r] % (MOD - 1);
}

ll get(int qs, int qe, int i, int s, int e)
{
    if (qs > e || qe < s)
    {
        return 1;
    }
    if (s >= qs && e <= qe)
    {
        return seg[i];
    }
    int l = 2 * i + 1, r = l + 1, m = (e + s) / 2;
    return get(qs, qe, l, s, m) * get(qs, qe, r, m + 1, e) % (MOD - 1);
}

ll get_ex(int ex, int s, int e)
{
    if (ex == s)
    {
        return get(s + 1, e, 0, s, e);
    }
    if (ex == e)
    {
        return get(s, e - 1, 0, s, e);
    }
    return get(s, ex - 1, 0, s, e) * get(ex + 1, e, 0, s, e) % (MOD - 1);
}

void run()
{
    int n, num = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &inp[i].first, &inp[i].second);
        num = num * (inp[i].second + 1ll) % MOD;
    }
    build(0, 0, n - 1);
    int sum = 1, pro = 1;
    for (int i = 0; i < n; i++)
    {
        sum = (sum + sum * g_sum(inp[i].first, inp[i].first, inp[i].second) % MOD) % MOD;
        pro = pro * my_pow(inp[i].first, get_ex(i, 0, n - 1) * (inp[i].second * (inp[i].second + 1ll) / 2 % (MOD - 1))) % MOD;
    }
    printf("%d %d %d\n", num, sum, pro);
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
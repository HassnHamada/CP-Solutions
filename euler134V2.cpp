#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

using namespace std;

#define ll long long int
#define ld long double

ll mul(ll a, ll b, ll mod)
{
    return ((a % mod) * (b % mod)) % mod;
}

ll add(ll a, ll b, ll mod)
{
    return ((a % mod) + (b % mod)) % mod;
}

ll pw(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return res;
}

vector<int> seg_sieve(ll l, ll r)
{
    vector<char> p(r - l + 1, true);
    ll lim = sqrt(r);
    for (int i = 2; i <= lim; i++)
        for (int j = max(1ll * i * i, (l + i - 1) / i * i); j <= r; j += i)
            p[j - l] = 0;
    if (l == 1)
        p[0] = 0;
    vector<int> primes;
    for (int i = 0; i < r - l + 1; i++)
        if (p[i])
            primes.push_back(i + l);
    return primes;
}

ll inv(ll a, ll mod)
{
    return pw(a, mod - 2, mod);
}

ll get(int t)
{
    ll ret = 1;
    while (t)
    {
        ret *= 10;
        t /= 10;
    }
    return ret;
}

void prn(vector<ll> &ans)
{
    ll e = 0;
    string s;
    while (true)
    {
        bool ok = false;
        ll v = e % 10;
        e /= 10;
        for (ll &i : ans)
        {
            v += i % 10;
            i /= 10;
            ok |= i;
        }
        s.push_back((v % 10) + '0');
        e += v / 10;
        if (!ok && e == 0)
        {
            break;
        }
    }
    reverse(s.begin(), s.end());
    printf("%s\n", s.c_str());
}

void solve()
{
    int l, r;
    scanf("%d%d", &l, &r);
    vector<int> v = seg_sieve(l, r + 1000);
    vector<ll> sum;
    for (int i = 0; i + 1 < (int)v.size() && v[i] <= r; i++)
    {
        ll b = v[i + 1] - v[i];
        ll a = get(v[i]);
        ll x = mul(b, inv(a, v[i + 1]), v[i + 1]);
        sum.push_back(a * x + v[i]);
    }
    prn(sum);
    // printf("%lld\n", sum);
}

int main()
{
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
    int tc;
    for (scanf("%d", &tc); tc--;)
        solve();
    return 0;
}

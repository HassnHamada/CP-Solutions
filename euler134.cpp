#include <bits/stdc++.h>

// #pragma GCC target("avx2")
// #pragma GCC optimization("O3")
// #pragma GCC optimization("unroll-loops")

using namespace std;

#define ll long long int

void seg_sieve(ll l, ll r, vector<int> &ret)
{
    vector<char> p(r - l + 1, true);
    ll lim = sqrt(r);
    for (int i = 2; i <= lim; i++)
        for (int j = max(1ll * i * i, (l + i - 1) / i * i); j <= r; j += i)
            p[j - l] = 0;
    if (l == 1)
        p[0] = 0;
    for (int i = 0; i < r - l + 1; i++)
        if (p[i])
            ret.push_back(i + l);
}

ll work(ll a, ll b, ll m = 10, ll c = 1, ll s = 0)
{
    for (int j = 1;; j++)
    {
        assert(a * (j * c + s) % (m / 10) == b % (m / 10));
        if (a * (j * c + s) % m == b % m)
        {
            return b / m ? work(a, b, m * 10, c * 10, j * c + s) : j * c + s;
        }
    }
    assert(false);
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
            // cout << i << endl;
            v += i % 10;
            i /= 10;
            ok |= i;
        }
        s.push_back((v % 10) + '0');
        // cout << s << endl;
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
    vector<int> v;
    seg_sieve(l, r + 1000, v);
    vector<ll> sum;
    for (int i = 1; i < (int)v.size() && v[i - 1] <= r; i++)
    {
        // cout << v[i - 1] << " " << v[i] << " " << work(v[i], v[i - 1]) * v[i] << endl;
        sum.push_back(work(v[i], v[i - 1]) * v[i]);
    }
    prn(sum);
    // printf("%lld\n", sum);
}

int main()
{
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    int tc;
    for (scanf("%d", &tc); tc--;)
        solve();
    return 0;
}

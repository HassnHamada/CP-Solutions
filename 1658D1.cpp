#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 63, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<ll> calc(ll s, ll e)
{
    if (s == 0)
    {
        vector<ll> ret(M);
        for (int i = 0; i < M; i++)
        {
            ret[i] = e / (1ll << (i + 1)) * (1ll << i);
            ret[i] = max(ret[i], ret[i] + e - ret[i] * 2 - (1ll << i));
        }
        return ret;
    }
    vector<ll> a = calc(0, e), b = calc(0, s);
    for (int i = 0; i < M; i++)
    {
        a[i] -= b[i];
        assert(a[i] >= 0);
    }
    return a;
}

void run()
{
    ll l, r;
    scanf("%lld%lld", &l, &r);
    auto res = calc(l, r + 1);
    // for (auto &&i : res)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    ll n = r - l + 1;
    vector<ll> vec(M);
    for (int i = 0; i < n; i++)
    {
        ll v;
        scanf("%lld", &v);
        for (int j = 0; j < M; j++)
        {
            vec[j] += (v >> j) & 1;
        }
    }
    // for (auto &&i : res)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto &&i : vec)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    ll ans = 0;
    for (int i = 0; i < M; i++)
    {
        if (res[i] == vec[i])
        {
            continue;
        }
        else if (res[i] == n - vec[i])
        {
            ans |= 1ll << i;
        }
        else
        {
            assert(false);
        }
    }
    printf("%lld\n", ans);
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

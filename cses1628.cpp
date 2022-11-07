#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

const int N = 5e5 + 10, M = 26, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, x;
    scanf("%d%d", &n, &x);
    vector<ll> vec(n);
    for (auto &&i : vec)
    {
        scanf("%lld", &i);
    }
    vector<int> v_1, v_2;
    for (int i = 0, j = n / 2; i < (1 << j); i++)
    {
        ll v = 0;
        for (int k = 0; k < j; k++)
        {
            if (i & (1 << k))
            {
                v += vec[k];
            }
        }
        if (v <= x)
        {
            v_1.push_back(v);
        }
    }
    for (int i = 0, j = (n + 1) / 2; i < (1 << j); i++)
    {
        ll v = 0;
        for (int k = 0; k < j; k++)
        {
            if (i & (1 << k))
            {
                v += vec[n / 2 + k];
            }
        }
        if (v <= x)
        {
            v_2.push_back(v);
        }
    }
    if (v_1.empty())
    {
        v_1.push_back(0);
    }
    sort(v_1.begin(), v_1.end());
    sort(v_2.begin(), v_2.end());
    ll ans = 0;
    int ii = 0, jj = v_2.size() - 1;
    while (ii < (int)v_1.size() && jj >= 0)
    {
        int ni = upper_bound(v_1.begin(), v_1.end(), v_1[ii]) - v_1.begin(),
            nj = lower_bound(v_2.begin(), v_2.end(), v_2[jj]) - v_2.begin();
        assert(ni == (int)v_1.size() || v_1[ii] < v_1[ni]);
        assert(nj == 0 || v_2[jj] > v_2[nj - 1]);
        if (v_1[ii] + v_2[jj] == x)
        {
            ans += (ni - ii) * (jj - nj + 1ll);
            ii = ni;
            jj = nj - 1;
        }
        else if (v_1[ii] + v_2[jj] < x)
        {
            ii = ni;
        }
        else if (v_1[ii] + v_2[jj] > x)
        {
            jj = nj - 1;
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
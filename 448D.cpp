#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    ll n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    auto rank = [&](ll x)
    {
        ll cnt = 0;
        for (ll i = 1; i <= n; i++)
        {
            cnt += min(m, (x - 1) / i);
        }
        return cnt;
    };
    ll l = 1, h = n * m;
    while (l < h)
    {
        ll mid = l + (h - l + 1) / 2;
        if (rank(mid) < k)
        {
            l = mid;
        }
        else
        {
            h = mid - 1;
        }
    }
    printf("%lld\n", l);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
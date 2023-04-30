#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll ok(ll n)
{
    if (n & 1)
    {
        n = (n + 1) / 2;
        return n * (n + 1) / 2 * 8 - 4 * n;
    }
    else
    {
        n /= 2;
        return n * (n + 1) / 2 * 8 + 1;
    }
}

void run()
{
    ll n;
    scanf("%lld", &n);
    ll l = 0, h = INF;
    while (l < h)
    {
        ll m = (h - l) / 2 + l;
        if (ok(m) >= n)
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }
    printf("%lld\n", h);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
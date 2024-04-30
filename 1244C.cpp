#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    ll n, p, w, d;
    scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
    ll x = p / w, y = -1;
    set<int> vis;
    for (; ~x; x--)
    {
        if ((p - w * x) % d == 0)
        {
            y = (p - w * x) / d;
            break;
        }
        if (vis.find((p - w * x) % d) != vis.end())
        {
            break;
        }
        vis.insert((p - w * x) % d);
    }
    if (~y && x + y <= n)
    {
        assert(~x);
        assert(w * x + d * y == p);
        printf("%lld %lld %lld\n", x, y, n - x - y);
    }
    else
    {
        printf("-1\n");
    }
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
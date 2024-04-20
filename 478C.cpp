#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    ll r, g, b;
    scanf("%lld%lld%lld", &r, &g, &b);
    ll mx = max({r, g, b}), tot = r + g + b;
    printf("%lld\n", min(tot - mx, tot / 3));
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
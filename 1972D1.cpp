#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    ll ans = 0;
    for (ll j = 1; j <= m; j++)
    {
        for (ll i = max(1ll, j * (j - 1)); i <= n; i += j * j)
        {
            ll mod = j * gcd(i, j);
            ans += (i + j) % mod == 0;
        }
    }
    printf("%lld\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    freopen("_error.txt", "w", stderr);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
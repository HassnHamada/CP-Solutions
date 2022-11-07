#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 100, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

// ll arr[N], ans[N];

void run()
{
    int n;
    scanf("%d", &n);
    ll ans = 0, mx = 0;
    for (ll i = 0, a, b; i < n; i++)
    {
        scanf("%lld%lld", &a, &b);
        ans += min(a, b);
        mx = max({mx, a, b});
    }
    printf("%lld\n", (ans + mx) * 2);
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
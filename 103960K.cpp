#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 448, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    ll n;
    scanf("%lld", &n);
    ll ans = 0, inv_2 = 500000004;
    for (ll i = 1; i <= n;)
    {
        // cout << i << endl;
        ll l = n / (i + 1), h = n / i;
        if (l == h)
        {
            i = n / l;
            assert(n / i == h);
            assert(n / (i + 1) != l);
            continue;
        }
        h %= MOD;
        l %= MOD;
        ans = (ans + (h * (h + 1) % MOD * inv_2 % MOD - l * (l + 1) % MOD * inv_2 % MOD + MOD) % MOD * i++ % MOD) % MOD;
    }
    printf("%lld\n", ans);
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
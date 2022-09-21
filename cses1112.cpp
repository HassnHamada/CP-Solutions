#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];

ll my_pow(ll b, ll p, ll m)
{
    ll ret = 1;
    while (p)
    {
        if (p & 1)
        {
            ret = (ret * b) % m;
        }
        b = (b * b) % m;
        p /= 2;
    }
    return ret;
}

void run()
{
    int n;
    scanf("%d%s", &n, str);
    int m = strlen(str);
    ll ans = 0;
    for (int i = 0; i <= n - m; i++)
    {
        ans = (ans + my_pow(26, i, MOD) * my_pow(26, n - m - i, MOD)) % MOD;
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
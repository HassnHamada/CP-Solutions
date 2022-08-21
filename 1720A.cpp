#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, L = 4, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

// ll ans[N], prv[N], cur[N];

void run()
{
    ll a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    ll e = a * d, f = c * b;
    if (e == f)
    {
        printf("0\n");
    }
    else if ((f && e % f == 0) || (e && f % e == 0))
    {
        printf("1\n");
    }
    else
    {
        printf("2\n");
    }
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

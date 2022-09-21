#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll my_pow(ll a, ll p)
{
    ll ret = 1;
    while (p)
    {
        if (p & 1)
        {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        p >>= 1;
    }
    return ret;
}

ll solve(int cn, int ck)
{
    if (cn == 0 || ck == 0)
    {
        return 1;
    }
    // return (solve(cn - 1, ck) + solve(cn - 1, ck - 1)) % MOD;
    if (cn > ck)
    {
        return (solve(cn - 1, ck) + ck * my_pow(2, ck - 1) - 1) % MOD;
    }
    return (solve(cn - 1, ck) + my_pow(2, cn - 1)) % MOD;
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%lld\n", solve(n, k));
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
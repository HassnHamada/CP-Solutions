#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll solve(ll n)
{
    for (ll i = 1; i < n; i *= 3)
    {
        if (n % i)
        {
            return n / i + solve(n % i);
        }
    }
    return 1;
}

void run()
{
    ll n;
    scanf("%lld", &n);
    printf("%lld\n", solve(n));
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
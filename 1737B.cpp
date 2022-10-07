#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e2 + 10, M = 128, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int acc[N];

// 1-3      -> 1
// 4-8      -> 2
// 9-15     -> 3
// 16-24    -> 4
// 25-35    -> 5
// 36-48    -> 6
// 36-49    -> 6

bool lux(int n)
{
    return n % (int)sqrt(n) == 0;
}

ll calc(ll n)
{
    if (n == 0)
    {
        return 0ll;
    }
    // ll sq = 1;
    // while ((sq + 1) * (sq + 1) <= n)
    // {
    //     sq++;
    // }
    ll sq = (ll)sqrt(n);
    ll b = sq * sq, l = 0;
    while (b + sq <= n)
    {
        // cout << b << " " << n << endl;
        b += sq;
        l += 1;
    }
    assert(l < 3);
    return (sq - 1) * 3 + l + 1;
}

void run()
{
    // for (int i = 1; i < N; i++)
    // {
    //     acc[i] = acc[i - 1] + lux(i);
    //     cout << calc(i) << " " << acc[i] << endl;
    // }
    ll l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", calc(r) - calc(l - 1));
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
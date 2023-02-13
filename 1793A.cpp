#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e3 + 10, M = 1e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int arr[N];

ll my_pow(ll b, ll p, ll m = MOD)
{
    b %= m;
    p %= (m - 1);
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = r * b % m;
        }
        p /= 2;
        b = b * b % m;
    }
    return r;
}

void run()
{
    int a, b, n, m;
    scanf("%d%d%d%d", &a, &b, &n, &m);
    // (m + 1)
    // n / (m + 1) * a * m
    // n / (m + 1) * b * (m + 1)
    printf("%lld\n", min(n / (m + 1ll) * a * m, n / (m + 1ll) * b * (m + 1)) + n % (m + 1ll) * min(a, b));
}

int main()
{
    freopen("_ok.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}

// dsadasdas

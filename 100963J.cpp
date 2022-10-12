#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e2 + 10, M = 3e5, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

ll ex_gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = ex_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll my_pow(ll b, ll p, ll m)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = r * b % m;
        }
        b = b * b % m;
        p = p / 2;
    }
    return r;
}

ll inv(ll a, ll mod)
{
    return my_pow(a % mod, mod - 2, mod);
}

// void run()
// {
//     while (true)
//     {
//         int o1, f1, o2, f2;
//         scanf("%d%d%d%d", &o1, &f1, &o2, &f2);
//         if (o1 == 0 && f1 == 0 && o2 == 0 && f2 == 0)
//         {
//             break;
//         }
//         int g = gcd(f1, f2);
//         if ((o2 - o1) % g == 0)
//         {
//             ll n1 = ((o2 - o1) / g * inv(f1 / g, f2 / g) % (f2 / g) + f2 / g) % (f2 / g),
//                n2 = ((o1 - o2) / g * inv(f2 / g, f1 / g) % (f1 / g) + f1 / g) % (f1 / g);
//             if ((n1 * f1 + o1 - o2) % f2)
//             {
//                 assert((n2 * f2 + o2 - o1) % f1 == 0);
//                 while (n2 * f2 + o2 < o1)
//                 {
//                     n2 += (f1 / g);
//                 }
//                 assert((n2 * f2 + o2 - o1) % f1 == 0);
//                 printf("%lld\n", n2 * f2 + o2);
//             }
//             else
//             {
//                 while (n1 * f1 + o1 < o2)
//                 {
//                     n1 += (f2 / g);
//                 }
//                 printf("%lld\n", n1 * f1 + o1);
//             }
//         }
//         else
//         {
//             printf("Impossible\n");
//         }
//     }
// }

void run()
{
    while (true)
    {
        ll o1, f1, o2, f2;
        scanf("%lld%lld%lld%lld", &o1, &f1, &o2, &f2);
        if (o1 == 0 && f1 == 0 && o2 == 0 && f2 == 0)
        {
            break;
        }
        o2 += f2;
        if (f1 == 0 && f2 == 0)
        {
            if (o1 == o2)
            {
                printf("%lld\n", o1);
            }
            else
            {
                printf("Impossible\n");
            }
            continue;
        }
        if (f1 == 0 || f2 == 0)
        {
            if (f2)
            {
                swap(o1, o2);
                swap(f1, f2);
            }
            if (o2 >= o1 && (o2 - o1) % f1 == 0)
            {
                printf("%lld\n", o2);
            }
            else
            {
                printf("Impossible\n");
            }
            continue;
        }
        ll x, y;
        ll g = ex_gcd(f1, f2, x, y);
        if ((o2 - o1) % g == 0)
        {
            ll f = f1 * f2 / g;
            ll n1 = (x % f * (o2 - o1) / g % f + f) % f,
               n2 = (y % f * (o1 - o2) / g % f + f) % f;
            // ll n1 = x * (o2 - o1) / g,
            //    n2 = y * (o1 - o2) / g;
            // assert((n2 * f2 + o2 - o1) % f1 == 0);
            // assert((n1 * f1 + o1 - o2) % f2 == 0);
            if (n2 * f2 + o2 < o1)
            {
                n2 += (o1 - n2 * f2 - o2 + f - 1) / f * f;
            }
            // assert(n2 * f2 + o2 >= max(o1, o2));
            printf("%lld\n", n2 * f2 + o2);
        }
        else
        {
            printf("Impossible\n");
        }
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
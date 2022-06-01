#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 5, MOD = 1e9 + 7, HV = 151;
char str[N];

// ll my_pow(ll b, ll p, ll m)
// {
//     ll r = 1;
//     while (p)
//     {
//         if (p & 1)
//         {
//             r = r * b % m;
//         }
//         b = b * b % m;
//         p = p / 2;
//     }
//     return r;
// }

// ll inv(ll a, ll mod)
// {
//     return my_pow(a, mod - 2, mod);
// }

// struct SHA
// {
//     ll v, b, m, s;
//     void hashBack(char l)
//     {
//         v = (v * b + l) % m;
//         s += 1;
//     }
//     void hashFront(char l)
//     {
//         v = (v + l * my_pow(b, s, m)) % m;
//         s += 1;
//     }
//     void unhashBack(char l)
//     {
//         v = (v - l + m) * inv(b, m) % m;
//         s -= 1;
//     }
//     void unhashFront(char l)
//     {
//         s -= 1;
//         v = (v - l * my_pow(b, s, m) % m + m) % m;
//     }
//     void extend(SHA &other)
//     {
//         assert(this->m == other.m && this->b == other.b);
//         v = (v * my_pow(b, other.s, m) + other.v) % m;
//         s += other.s;
//     }
// };

void run()
{
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 1; i <= n; i++)
    {
        if (n % i)
        {
            continue;
        }
        bool ok = true;
        for (int j = i; j < n; j += i)
        {
            for (int k = 0; k < i; k++)
            {
                ok &= str[k] == str[j + k];
            }
        }
        if (ok)
        {
            printf("%d\n", i);
            return;
        }
    }
    // printf("%d\n\n", n);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        run();
        if (t)
        {
            printf("\n");
        }
    }
    return 0;
}
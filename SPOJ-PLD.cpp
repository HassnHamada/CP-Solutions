#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e4 + 5, MOD = 1e9 + 7, HV = 151;
char str[N];

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
    return my_pow(a, mod - 2, mod);
}

struct SHA
{
    ll v, b, m, s;
    void hashBack(char l)
    {
        v = (v * b + l) % m;
        s += 1;
    }
    void hashFront(char l)
    {
        v = (v + l * my_pow(b, s, m)) % m;
        s += 1;
    }
    void unhashBack(char l)
    {
        v = (v - l + m) * inv(b, m) % m;
        s -= 1;
    }
    void unhashFront(char l)
    {
        s -= 1;
        v = (v - l * my_pow(b, s, m) % m + m) % m;
    }
    void extend(SHA &other)
    {
        assert(this->m == other.m && this->b == other.b);
        v = (v * my_pow(b, other.s, m) + other.v) % m;
        s += other.s;
    }
} hash1{0, HV, MOD, 0}, hash2{0, HV, MOD, 0};

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int k;
    scanf("%d%s\n", &k, str);
    for (int i = 0; i < k; i++)
    {
        hash1.hashBack(str[i]);
        hash2.hashFront(str[i]);
    }

    int ans = hash1.v == hash2.v;
    for (int i = k; str[i]; i++)
    {
        hash1.unhashFront(str[i - k]);
        hash1.hashBack(str[i]);
        hash2.unhashBack(str[i - k]);
        hash2.hashFront(str[i]);
        if (hash1.v == hash2.v)
        {
            ans += 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
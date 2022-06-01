#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 5, MOD = 1e9 + 7, HV = 151;
char str[N];
int ppp[N];

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
};

int ok(int k)
{
    SHA hash1{0, HV, MOD, 0}, hash2{0, HV, MOD, 0};
    // cout << k << endl;
    for (int i = 0; i < k; i++)
    {
        if (!str[i])
        {
            return false;
        }
        hash1.hashBack(str[i]);
        hash2.hashFront(str[i]);
    }
    if (hash1.v == hash2.v)
    {
        return true;
    }
    for (int i = k; str[i]; i++)
    {
        hash1.unhashFront(str[i - k]);
        hash1.hashBack(str[i]);
        hash2.unhashBack(str[i - k]);
        hash2.hashFront(str[i]);
        if (hash1.v == hash2.v)
        {
            return true;
        }
    }
    return false;
}

int bs(int n, bool odd)
{
    int l = 0, h = n / 2;
    while (l <= h)
    {
        // cout << l << " " << h << endl;
        int m = l + (h - l) / 2;
        // cout << l << " " << h << " " << m << endl;
        if (ok(2 * m + odd))
        {
            // cout << "HI\n";
            l = m + 1;
        }
        else
        {
            // cout << "NOT HI\n";
            h = m - 1;
        }
    }
    return 2 * (l - 1) + odd;
}

void extend()
{
    int n = strlen(str);
    for (int i = (n + 1) * 2; i; i -= 2)
    {
        str[i] = str[n--];
        str[i - 1] = '#';
    }
    str[0] = '$';
}

void manacher()
{
    extend();
    ppp[0] = 0;
    int c = 0;
    for (int i = 1; str[i]; i++)
    {
        if (i < c + ppp[c])
        {
            ppp[i] = min(c + ppp[c] - i, ppp[2 * c - i]);
        }
        while (str[i + ppp[i] + 1] == str[i - ppp[i] - 1])
        {
            ppp[i]++;
        }
        if (i + ppp[i] > c + ppp[c])
        {
            c = i;
        }
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int n;
    scanf("%d%s\n", &n, str);
    manacher();
    printf("%d\n", *max_element(ppp, ppp + strlen(str)));
    // for (int i = 0; i < (int)strlen(str); i++)
    // {
    //     printf("%c %d\n", str[i], ppp[i]);
    // }
    return 0;
}
#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <iostream>
#endif
using namespace std;
typedef long long ll;

const int N = (int)(1e6 + 10), MOD = (int)(1e9 + 7), HV = 151;
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
        v = (v - l * my_pow(b, s, m) + m) % m;
    }
    void extend(SHA &other)
    {
        assert(this->m == other.m && this->b == other.b);
        v = (v * my_pow(b, other.s, m) + other.v) % m;
        s += other.s;
    }
};

bool ok(int sz, int hv, int n)
{
    cout << sz << " " << hv << "\n";
    if (sz == 0)
    {
        return true;
    }
    SHA h = {0, HV, MOD, 0};
    for (int i = 1; i < n - 1; i++)
    {
        h.hashBack(str[i]);

        // cout << "Add " << str[i] << " " << h.v  << "\n";
        if (h.s == sz)
        {
            if (h.v == hv)
            {
                return true;
            }
            h.unhashFront(str[i - sz + 1]);
            // cout << "Rem " << str[i - sz + 1] << " " << h.v << "\n";
        }
        assert(h.s < sz);
    }
    return false;
}

void run()
{
    scanf("%s", str);
    int n = (int)strlen(str);
    vector<pair<int, int>> good;
    good.emplace_back(0, 0);
    SHA hf = {0, HV, MOD, 0}, hb = {0, HV, MOD, 0};
    for (int i = 0; i < n - 1; i++)
    {
        hf.hashBack(str[i]);
        hb.hashFront(str[n - i - 1]);
        if (hf.v == hb.v)
        {
            good.emplace_back(i + 1, hf.v);
        }
    }
    for (auto &&[i, j] : good)
    {
        printf("%d %d\n", i, j);
    }
    unsigned int l = 0, h = (unsigned int)good.size() - 1;
    while (l < h)
    {
        unsigned int m = l + (h - l + 1) / 2;
        // cout << l << " " << m << " " << h << "\n";
        if (ok(good[m].first, good[m].second, n))
        {
            l = m;
        }
        else
        {
            h = m - 1;
        }
    }
    if (l)
    {
        str[good[l].first] = '\0';
        printf("%s\n", str);
    }
    else
    {
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
// #include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;
// typedef long long int ll;
#include <chrono>
using namespace std::chrono;

const int N = 1 << 20, MOD = 1e9 + 7, HV = 151;
string str;
int n, my_pow[N];

// ll my_pow(ll b, ll p, ll m = INT64_MAX)
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

struct SHA
{
    int v, b, m, s;
    // void hashBack(char l)
    // {
    //     v = (v * b + l) % m;
    //     s += 1;
    // }
    // void hashFront(char l)
    // {
    //     v = (v + l * my_pow(b, s, m)) % m;
    //     s += 1;
    // }
    // void unhashBack(char l)
    // {
    //     v = (v - l + m) * inv(b, m) % m;
    //     s -= 1;
    // }
    // void unhashFront(char l)
    // {
    //     s -= 1;
    //     v = (v - l * my_pow(b, s, m) + m) % m;
    // }
    void extend(SHA &other)
    {
        assert(this->m == other.m && this->b == other.b);
        // v = (v * my_pow(b, other.s, m) + other.v) % m;
        v = (1ll * v * my_pow[other.s] + other.v) % m;
        s += other.s;
    }
} seg[N << 1], EMP{0, HV, MOD, 0};

void build(int i = 0, int s = 0, int e = n - 1)
{
    if (s == e)
    {
        seg[i] = {str[s], HV, MOD, 1};
    }
    else
    {
        int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
        build(l, s, m);
        build(r, m + 1, e);
        seg[i] = seg[l];
        seg[i].extend(seg[r]);
    }
    // cout << s << " " << e << " " << seg[i].v << endl;
}

SHA get(int qs, int qe, int i = 0, int s = 0, int e = n - 1)
{
    if (qs > e || qe < s)
    {
        return EMP;
    }
    if (s >= qs && e <= qe)
    {
        return seg[i];
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    SHA ret = get(qs, qe, l, s, m),
        tem = get(qs, qe, r, m + 1, e);
    ret.extend(tem);
    return ret;
}

void run()
{
    my_pow[0] = 1;
    for (int i = 1; i < N; i++)
    {
        my_pow[i] = 1ll * my_pow[i - 1] * HV % MOD;
    }
    cin >> str;
    n = str.size();
    build();
    for (int i = 1; i <= n; i++)
    {
        int lp = n % i;
        bool ok = lp == 0 || get(0, lp - 1).v == get(n - lp, n - 1).v;
        int hv = get(0, i - 1).v;
        for (int j = i; ok && j + i <= n; j += i)
        {
            ok = hv == get(j, j + i - 1).v;
        }
        if (ok)
        {
            cout << i << " \n"[i == n];
        }
    }
}

int main(int argc, char const *argv[])
{
    auto start = high_resolution_clock::now();
    freopen(".\\_input.txt", "r", stdin);
    freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(6) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e3 + 10, M = 26, MOD = 1e9 + 9, HV = 151, HV2 = 167, INF = 0x3f3f3f3f;

char str[N];
bitset<M> good;

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

void run()
{
    scanf("%s\n", str);
    for (int i = 0; i < M; i++)
    {
        char c;
        scanf("%c", &c);
        good[i] = c == '1';
    }
    int k, n = strlen(str);
    scanf("%d", &k);
    set<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        SHA h = {0, HV, MOD, 0};
        SHA h2 = {0, HV2, MOD, 0};
        for (int j = i, b = 0; j < n; j++)
        {
            h.hashBack(str[j]);
            h2.hashBack(str[j]);
            if (!good[str[j] - 'a'])
            {
                if (b++ == k)
                {
                    break;
                }
            }
            ans.insert({h.v, h2.v});
        }
    }
    printf("%d\n", (int)ans.size());
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
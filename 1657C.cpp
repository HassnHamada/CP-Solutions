#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10, M = 26, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];

ll my_pow(ll b, ll p, ll m = INT64_MAX)
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

struct HASH
{
    ll v, b, m, s;

    HASH(ll b, ll m)
    {
        this->v = 0;
        this->b = b;
        this->m = m;
        this->s = 0;
    }
    HASH(ll b, ll m, char *str)
    {
        this->v = 0;
        this->b = b;
        this->m = m;
        this->s = 0;
        for (int i = 0; str[i]; i++)
        {
            this->hashBack(str[i]);
        }
    }

    void clear()
    {
        this->v = 0;
        this->b = b;
        this->m = m;
        this->s = 0;
    }

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
    void extend(HASH &other)
    {
        assert(this->m == other.m && this->b == other.b);
        v = (v * my_pow(b, other.s, m) + other.v) % m;
        s += other.s;
    }
};

void run()
{
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    int c = 0, r = n;
    vector<char> stk;
    struct HASH h1 = HASH(HV, MOD), h2 = HASH(HV, MOD);
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ')')
        {
            if (stk.empty())
            {
                stk.push_back(')');
            }
            else if (stk.back() == '(')
            {
                stk.pop_back();
            }
        }
        else
        {
            if (stk.empty() || stk.back() == '(')
            {
                stk.push_back('(');
            }
        }
        h1.hashBack(str[i]);
        h2.hashFront(str[i]);
        // cout << stk.size() << " " << h1.v << " " << h2.v << endl;
        if (stk.empty() || (h1.s > 1 && h1.v == h2.v))
        {
            h1.clear();
            h2.clear();
            stk.clear();
            c += 1;
            r = n - i - 1;
        }
    }
    printf("%d %d\n", c, r);
    // printf(ok ? "YES\n" : "NO\n");
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
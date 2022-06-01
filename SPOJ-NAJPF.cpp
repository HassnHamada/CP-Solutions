#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5, M = 1e3 + 5, MOD = 1e9 + 7, HV = 151;
char str[N << 1], pat[N];
int fff[N << 1], zzz[N << 1];

int newL(int l, char c)
{
    while (l && str[l] != c)
    {
        l = fff[l - 1];
    }
    return l + (str[l] == c);
}

void computeF()
{
    fff[0] = 0;
    for (int i = 1; str[i]; i++)
    {
        fff[i] = newL(fff[i - 1], str[i]);
    }
}

void computeZ()
{
    int s = 0, e = 0;
    int &i = zzz[0];
    for (i = 1; str[i]; i++)
    {
        if (i >= e)
        {
            s = e = i;
            zzz[i] = 0;
        }
        else
        {
            zzz[i] = zzz[i - s];
        }
        if (zzz[i] + i >= e)
        {
            s = i;
            while (str[e] == str[e - s])
            {
                e++;
            }
            zzz[i] = e - s;
        }
    }
}

struct SHA
{
    ll v, b, m, s;

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

void run1()
{
    scanf("%s%s", pat, str);
    computeF();
    vector<int> ans;
    for (int i = 0, l = 0; pat[i]; i++)
    {
        l = newL(l, pat[i]);
        if (!str[l])
        {
            ans.push_back(i - l + 2);
        }
    }
    if (ans.empty())
    {
        printf("Not Found\n\n");
    }
    else
    {
        printf("%d\n", (int)ans.size());
        for (auto &&i : ans)
        {
            printf("%d ", i);
        }
        printf("\n\n");
    }
}

void run2()
{
    scanf("%s%s", pat, str);
    int patLen = strlen(pat), strLen = strlen(str);
    strcpy(str + strLen + 1, pat);
    str[strLen] = '$';
    computeF();
    vector<int> ans;
    for (int i = 0; i <= strLen + patLen; i++)
    {
        if (fff[i] == strLen)
        {
            ans.push_back(i - 2 * strLen + 1);
        }
    }
    if (ans.empty())
    {
        printf("Not Found\n\n");
    }
    else
    {
        printf("%d\n", (int)ans.size());
        for (auto &&i : ans)
        {
            printf("%d ", i);
        }
        printf("\n\n");
    }
}

void run3()
{
    scanf("%s%s", pat, str);
    int patLen = strlen(pat), strLen = strlen(str);
    strcpy(str + strLen + 1, pat);
    str[strLen] = '$';
    computeZ();
    vector<int> ans;
    for (int i = 0; i <= strLen + patLen; i++)
    {
        if (zzz[i] == strLen)
        {
            ans.push_back(i - strLen);
        }
    }
    if (ans.empty())
    {
        printf("Not Found\n\n");
    }
    else
    {
        printf("%d\n", (int)ans.size());
        for (auto &&i : ans)
        {
            printf("%d ", i);
        }
        printf("\n\n");
    }
}

void run4()
{
    scanf("%s%s", pat, str);
    int patLen = strlen(pat), strLen = strlen(str);
    // strcpy(str + strLen + 1, pat);
    SHA hash1{0, HV, MOD, 0}, hash2{0, HV, MOD, 0};
    for (int i = 0; i < min(strLen, patLen); i++)
    {
        hash1.hashBack(str[i]);
        hash2.hashBack(pat[i]);
    }
    vector<int> ans;
    if (hash1.v == hash2.v && patLen >= strLen)
    {
        ans.push_back(1);
    }
    for (int i = strLen; i < patLen; i++)
    {
        hash2.unhashFront(pat[i - strLen]);
        hash2.hashBack(pat[i]);
        if (hash1.v == hash2.v)
        {
            ans.push_back(i - strLen + 2);
        }
    }
    if (ans.empty())
    {
        printf("Not Found\n\n");
    }
    else
    {
        printf("%d\n", (int)ans.size());
        for (auto &&i : ans)
        {
            printf("%d ", i);
        }
        printf("\n\n");
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        // run1();
        // run2();
        // run3();
        run4();
    }
    return 0;
}
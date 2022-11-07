#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 1e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll my_pow(ll b, ll p, ll m = MOD)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = (r * b) % m;
        }
        b = (b * b) % m;
        p /= 2;
    }
    return r;
}
char str[N];

int pi[N];

int newL(int i, char c)
{
    while (i && str[i] != c)
    {
        i = pi[i - 1];
    }
    return i + (int)(str[i] == c);
}

void kmp()
{
    for (int i = 1; str[i]; i++)
    {
        pi[i] = newL(pi[i - 1], str[i]);
    }
}

int dp[N][M];

ll solve(int n, int m, int cm)
{
    if (cm == m)
    {
        return my_pow(26, n);
    }
    if (n <= m - cm)
    {
        return n == m - cm;
    }
    int &ret = dp[n][cm];
    if (~ret)
    {
        return ret;
    }
    ret = 0;
    for (int i = 0; i < 26; i++)
    {
        ret = (ret + solve(n - 1, m, newL(cm, i + 'A'))) % MOD;
    }
    return ret;
}

void run()
{
    memset(dp, -1, sizeof(dp));
    int n;
    scanf("%d%s", &n, str);
    int m = strlen(str);
    kmp();
    printf("%lld\n", solve(n, m, 0));
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
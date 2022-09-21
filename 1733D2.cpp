#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

const int N = 5e3 + 10, M = 2, L = 4, MOD = 1e9 + 7, HV1 = 151, HV2 = 163, INF = 0x3f3f3f3f;

char aaa[N], bbb[N];
bool ccc[N];
int nxt[N];
ll dp[N];

int n;
ll x, y;

ll calc(int a, int b)
{
    assert(a < b);
    if (b == a + 1)
    {
        return min(x, 4 * y);
    }
    return min((b - a) * x, 2 * y);
}

ll solve(int cn)
{
    if (cn == n)
    {
        return 0;
    }
    ll &ret = dp[cn];
    if (~ret)
    {
        return ret;
    }
    ret = solve(nxt[cn]) + y;
    if (nxt[cn] != n)
    {
        ret = min(ret, solve(nxt[nxt[cn]]) + calc(cn, nxt[cn]));
    }
    return ret;
}

void run()
{
    scanf("%d%lld%lld", &n, &x, &y);
    scanf("%s\n%s", aaa, bbb);
    for (int i = 0; i < n; i++)
    {
        ccc[i] = aaa[i] != bbb[i];
    }
    if (count(ccc, ccc + n, true) & 1)
    {
        printf("-1\n");
    }
    else
    {
        int j = n;
        for (int i = n - 1; ~i; i--)
        {
            if (ccc[i])
            {
                nxt[i] = j;
                j = i;
            }
        }
        if (j == n)
        {
            printf("0\n");
        }
        else if (nxt[nxt[j]] == n && j + 1 == nxt[j])
        {
            printf("%lld\n", min(x, 2 * y));
        }
        else
        {
            x *= 2;
            memset(dp, -1, sizeof(dp[0]) * n);
            printf("%lld\n", solve(j) / 2);
        }
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
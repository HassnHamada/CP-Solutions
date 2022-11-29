#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e3 + 10, M = 1 << 12, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

ll arr[N], dp[N][N], pre[N][N], suf[N][N], cst[N][N];

int bs(int l, int h, int s, int e)
{
    while (l < h)
    {
        int m = (h - l) / 3;
        ll a = pre[s][l + m - 1] + suf[l + m][e],
           b = pre[s][h - m - 1] + suf[h - m][e],
           c = pre[s][l - 1] + suf[l][e];
        if (a <= b || c <= min(a, b))
        {
            h = h - m - 1;
        }
        else
        {
            l = l + m + 1;
        }
    }
    assert(l == h);
    return l;
}

int bs_(int l, int h, int k, int s)
{
    while (l < h)
    {
        int m = (h - l) / 3;
        ll a = dp[k][l + m] + cst[s][l + m],
           b = dp[k][h - m] + cst[s][h - m],
           c = dp[k][l] + cst[s][l];
        if (a <= b || c <= min(a, b))
        {
            h = h - m - 1;
        }
        else
        {
            l = l + m + 1;
        }
    }
    return l;
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", arr + i);
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            pre[i][j] = arr[j] - arr[i] + pre[i][j - 1];
            suf[i][j] = (arr[j] - arr[j - 1]) * (j - i) + suf[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1, l = i; j <= n; j++)
        {
            l = bs(l, j, i, j);
            cst[i][j] = pre[i][l - 1] + suf[l][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = cst[i][n];
    }
    for (int i = 1; i < k; i++)
    {
        for (int j = 0, l = 1; j < n - i; j++)
        {
            l = bs_(l, n - i, i - 1, j);
            dp[i][j] = dp[i - 1][l] + cst[j][l];
        }
    }
    printf("%lld\n", dp[k - 1][0]);
}

int main()
{
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

struct DT
{
    int t, f;
    DT operator+(const DT &other) const
    {
        return DT{t + other.t, f + other.f};
    }
} mat[N][N], dp[N][N];

void run()
{
    int n;
    scanf("%d", &n);
    pair<int, int> z{-1, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0, v; j < n; j++)
        {
            scanf("%d", &v);
            if (v == 0)
            {
                z = {i, j};
                mat[i][j] = {0, 0};
                continue;
            }
            while (v % 2 == 0)
            {
                mat[i][j].t++;
                v /= 2;
            }
            while (v % 5 == 0)
            {
                mat[i][j].f++;
                v /= 5;
            }
        }
    }
    dp[n - 1][n - 1] = mat[n - 1][n - 1];
    for (int i = n - 2; ~i; i--)
    {
        dp[n - 1][i] = mat[n - 1][i] + dp[n - 1][i + 1];
    }
    for (int i = n - 2; ~i; i--)
    {
        dp[i][n - 1] = mat[i][n - 1] + dp[i + 1][n - 1];
    }
    for (int i = n - 2; ~i; i--)
    {
        for (int j = n - 2; ~j; j--)
        {
            DT u = mat[i][j] + dp[i + 1][j],
               v = mat[i][j] + dp[i][j + 1];
            dp[i][j] = DT{min(u.t, v.t), min(u.f, v.f)};
        }
    }
    if (z.first == -1 || min(dp[0][0].t, dp[0][0].f) == 0)
    {
        printf("%d\n", min(dp[0][0].t, dp[0][0].f));
        int i = 0, j = 0;
        bool t = dp[0][0].t < dp[0][0].f;
        while (true)
        {
            if (i + 1 == n && j + 1 == n)
            {
                printf("\n");
                break;
            }
            bool d = i + 1 < n && (t ? dp[i][j].t - mat[i][j].t == dp[i + 1][j].t
                                     : dp[i][j].f - mat[i][j].f == dp[i + 1][j].f);
            printf(d ? "D" : "R");
            (d ? i : j)++;
        }
    }
    else
    {
        printf("1\n");
        for (int i = 0; i < z.first; i++)
        {
            printf("D");
        }
        for (int i = 0; i < z.second; i++)
        {
            printf("R");
        }
        for (int i = z.first; i < n - 1; i++)
        {
            printf("D");
        }
        for (int i = z.second; i < n - 1; i++)
        {
            printf("R");
        }
        printf("\n");
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
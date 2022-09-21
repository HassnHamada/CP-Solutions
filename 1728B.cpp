#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 1e2 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int dp[N][N << 1];
int usd[N];
int n;

int solve(int cn, int cx)
{
    if (cn == n)
    {
        return dp[cn][cx] = cx;
    }
    if (dp[cn][cx] == -1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (usd[i])
            {
                continue;
            }
            usd[i] = true;
            dp[cn][cx] = max(dp[cn][cx], solve(cn + 1, cx < i ? cx + i : 0));
            usd[i] = false;
        }
    }
    return dp[cn][cx];
}

void prn(int cn, int cx, int t)
{
    for (int i = 1; i <= n; i++)
    {
        int nx = cx < i ? cx + i : 0;
        if (dp[cn + 1][nx] == t && !usd[i])
        {
            printf("%d%c", i, " \n"[cn + 1 == n]);
            usd[i] = true;
            if (cn + 1 < n)
            {
                prn(cn + 1, nx, t);
            }
            usd[i] = false;
            break;
        }
    }
}

void run()
{
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    prn(0, 0, solve(0, 0));
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
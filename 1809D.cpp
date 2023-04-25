#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char inp[N];
int dp[2][N];

int solve(int c, int n)
{
    if (c == n)
    {
        return 0;
    }
    int &ret = dp[inp[c] == '1'][c];
    if (~ret)
    {
        return ret;
    }
    if (inp[c] == '0')
    {
        if (c + 1 < n)
        {
        }
        else
        {
        }
    }
    else
    {
    solve(c + 1, n);
        if (c + 1 < n)
        {
        }
        else
        {
        }
    }
    return solve(c + 1, n, r + 1, k - r - 1, v + 2);
}

void run()
{
    scanf("%s", inp);
    int n = strlen(inp);
    memset(dp, -1, sizeof(dp[0]) * n * 2);
    solve(0, n);
    printf("%d%c", ans[i], " \n"[i + 1 == n]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
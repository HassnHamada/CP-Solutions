#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 15, M = 1e2 + 5, MOD = 32768, HV = 151, INF = 0x3f3f3f3f;
int n, dp[1 << N][M], dp2[1 << N][M], arr[N];

int solve(int cn, int m)
{
    if (cn == (1 << n) - 1)
    {
        return m;
    }
    int &ret = dp[cn][m];
    if (~ret)
    {
        return ret;
    }
    for (int i = 0; i < n; i++)
    {
        if (cn & (1 << i))
        {
            continue;
        }
        ret = max(ret, 2 + abs(arr[i] - m) + solve(cn | (1 << i), arr[i]));
    }
    return ret;
}

int perm(int cn, int m)
{
    if (cn == (1 << n) - 1)
    {
        return 1;
    }
    int &ref = dp[cn][m];
    if (ref == -1)
    {
        return 0;
    }
    int &ret = dp2[cn][m];
    if (~ret)
    {
        return ret;
    }
    ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (cn & (1 << i))
        {
            continue;
        }
        if (2 + abs(arr[i] - m) + solve(cn | (1 << i), arr[i]) == ref)
        {
            ret += perm(cn | (1 << i), arr[i]);
        }
    }
    return ret;
}

void run()
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    solve(0, 0);
    printf("%d %d\n", dp[0][0], perm(0, 0));
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // int t = 1;
    // scanf("%d", &t);
    // while (t--)
    while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
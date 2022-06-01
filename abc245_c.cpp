#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int n, k, arr[2][N], dp[2][N];

int dfs(int c, int p)
{
    if (c == n - 1)
    {
        return 1;
    }
    if (~dp[p][c])
    {
        return dp[p][c];
    }
    if (abs(arr[p][c] - arr[0][c + 1]) <= k && dfs(c + 1, 0))
    {
        return dp[p][c] = 1;
    }
    if (abs(arr[p][c] - arr[1][c + 1]) <= k && dfs(c + 1, 1))
    {
        return dp[p][c] = 1;
    }
    return dp[p][c] = 0;
}

void run()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (int *)(arr) + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (int *)(arr + 1) + i);
    }
    printf(dfs(0, 0) || dfs(0, 1) ? "Yes\n" : "No\n");
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
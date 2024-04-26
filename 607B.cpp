#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e2 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], dp[N][N];

int solve(int i, int j)
{
    assert(i <= j);
    if (i == j)
    {
        return 0;
    }
    if (i + 1 == j)
    {
        return 1;
    }
    if (i + 2 == j)
    {
        return arr[i] == arr[j - 1] ? 1 : 2;
    }
    assert(j - i >= 3);
    if (dp[i][j] == -1)
    {
        dp[i][j] = min({solve(i, j - 1) + 1, solve(i + 1, j) + 1,
                        solve(i + 1, j - 1) + (arr[i] == arr[j - 1] ? 0 : 2)});
        for (int k = i + 1; k < j; k++)
        {
            dp[i][j] = min(dp[i][j], solve(i, k) + solve(k, j));
        }
    }
    return dp[i][j];
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, n));
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
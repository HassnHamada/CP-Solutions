#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], dp[2][N];

int solve(int i, int n, int t)
{
    if (i == n - 1)
    {
        return t;
    }
    if (~dp[t][i])
    {
        return dp[t][i];
    }
    if (arr[i] == 1)
    {
        int w = solve(i + 1, n, t ^ 1);
        return dp[t][i] = w;
    }
    int w = solve(i + 1, n, t ^ 1),
        v = solve(i + 1, n, t);
    return dp[t][i] = (w == t || v == t ? t : (t ^ 1));
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n);
    int m = unique(arr, arr + n) - arr;
    for (int i = m - 1; i; i--)
    {
        arr[i] -= arr[i - 1];
    }
    memset(dp, -1, sizeof(dp[0][0]) * m);
    memset(dp + 1, -1, sizeof(dp[0][0]) * m);
    printf(solve(0, m, 1) ? "Alice\n" : "Bob\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
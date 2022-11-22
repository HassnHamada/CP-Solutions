#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 50, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], dp[M][M];

int solve(int e, int m, int k)
{
    if (e == 0 || m == 0 || k == 0)
    {
        return 0;
    }
    if (~dp[m][k])
    {
        return dp[m][k];
    }
    int in_1 = solve(e, m - 1, k - 1) | (1 << (m - 1)),
        in_2 = solve(e, m - 1, k);
    ll res_1 = 0, res_2 = 0;
    for (int i = 0; i < e; i++)
    {
        res_1 += arr[i] ^ in_1;
        res_2 += arr[i] ^ in_2;
    }
    return dp[m][k] = res_1 > res_2 ? in_1 : in_2;
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    ll ans = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        mx += arr[i];
    }
    for (int i = 1; k && i <= m; i++)
    {
        auto cmp = [&i](int a, int b)
        { return a % (1ll << i) < b % (1ll << i); };
        sort(arr, arr + n, cmp);
        auto it = lower_bound(arr, arr + n, 1 << (i - 1), cmp) - arr;
        memset(dp, -1, sizeof(dp));
        int in_1 = solve(it, i - 1, k - 1) | (1 << (i - 1));
        ll res_1 = 0;
        for (int j = 0; j < n; j++)
        {
            res_1 += max(arr[j], arr[j] ^ in_1);
        }
        if (res_1 > mx)
        {
            mx = res_1;
            ans = in_1;
        }
    }
    printf("%lld\n", ans);
    // printf("%lld %lld\n", ans, mx);
    return 0;
}
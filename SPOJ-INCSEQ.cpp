#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 10, M = 50, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int n, k, dp[N][M], arr[N];
// map<pair<int, pair<int, int>>, int> dp;

// int solve(int cn, int pn, int ck)
// {
//     if (ck == k)
//     {
//         return 1;
//     }
//     if (cn == n + 1)
//     {
//         return 0;
//     }
//     pair<int, pair<int, int>> key = {cn, {pn, ck}};
//     if (dp.find(key) != dp.end())
//     {
//         return dp[key];
//     }
//     dp[key] = solve(cn + 1, pn, ck) % MOD;
//     if (arr[cn] > arr[pn])
//     {
//         dp[key] = (dp[key] + solve(cn + 1, cn, ck + 1)) % MOD;
//     }
//     return dp[key];
// }

void run()
{
    scanf("%d%d", &n, &k);
    set<pair<int, int>> sss;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        sss.insert({arr[i], i});
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = sss.lower_bound({arr[i], INF});
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
        }
    }

    // arr[0] = -INF;
    // printf("%d\n", solve(1, 0, 0));
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
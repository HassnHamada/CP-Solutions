#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e3 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];
map<int, int> freq;
ll dp[N][N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        freq[arr[i]]++;
    }
    sort(arr, arr + n);
    int m = unique(arr, arr + n) - arr;
    auto calc = [&m](int i, int j, auto f) -> ll
    {
        if (~dp[i][j])
        {
            return dp[i][j];
        }
        int ii = i - 1, jj = j + 1;
        if (ii >= 0 && jj <= m - 1)
        {
            auto lit = freq.find(arr[ii]),
                 rit = freq.find(arr[jj]);
            assert(lit != freq.end());
            assert(rit != freq.end());
            ll l = 1ll * (arr[j] - lit->first) * lit->second,
               r = 1ll * (rit->first - arr[i]) * rit->second;
            assert(l > 0);
            assert(r > 0);
            return dp[i][j] = min(l + f(ii, j, f), r + f(i, jj, f));
        }
        if (ii >= 0)
        {
            auto lit = freq.find(arr[ii]);
            assert(lit != freq.end());
            ll l = 1ll * (arr[j] - lit->first) * lit->second;
            assert(l > 0);
            return dp[i][j] = l + f(ii, j, f);
        }
        if (jj <= m - 1)
        {
            auto rit = freq.find(arr[jj]);
            assert(rit != freq.end());
            ll r = 1ll * (rit->first - arr[i]) * rit->second;
            assert(r > 0);
            return dp[i][j] = r + f(i, jj, f);
        }
        return dp[i][j] = 0;
    };
    memset(dp, -1, sizeof(dp));
    ll ans = 1ll * INF * INF;
    for (int i = 0; i < m; i++)
    {
        cerr << arr[i] << " " << calc(i, i, calc) << endl;
        ans = min(ans, calc(i, i, calc));
    }
    printf("%lld\n", ans);
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
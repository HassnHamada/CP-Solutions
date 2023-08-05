// #include <bits/stdc++.h>
#include <stdio.h>
#include <memory.h>
#include <map>
#include <iostream>
using namespace std;
typedef long long ll;

// const int N = 2e5 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
const int N = 2e5 + 10, M = 2;

struct DT
{
    ll v, h, b;
} dp[M][N];

map<pair<int, int>, int> val;

void run()
{
    int n, k, a;
    scanf("%d%d%d", &n, &k, &a);
    for (int i = 0; i < n; i++)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        val.insert({{x, y}, c});
    }
    for (int i = k - 1; ~i; i--)
    {
        int p = i & 1;
        for (int j = 0; j <= i; j++)
        {
            pair<int, int> ky = {j, i - j};
            int v = val.find(ky) == val.end() ? 0 : val[ky];
            dp[p][j].b = min({dp[p ^ 1][j].b + dp[p ^ 1][j + 1].h + v,
                              dp[p ^ 1][j + 1].b + dp[p ^ 1][j].v + v,
                              1ll * (k - i) * a});
            dp[p][j].v = min({dp[p ^ 1][j].b + v,
                              dp[p ^ 1][j].v + v,
                              1ll * (k - i) * a});
            dp[p][j].h = min({dp[p ^ 1][j + 1].b + v,
                              dp[p ^ 1][j + 1].h + v,
                              1ll * (k - i) * a});
            if (v)
            {
                cout << ky.first << " " << ky.second << endl;
                cout << dp[p][j].b << " " << dp[p][j].v << " " << dp[p][j].h << endl;
            }
            // cout << dp[p][j].b << " ";
        }
        // cout << "\n";
    }
    // printf("%lld\n", dp[0][0].b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
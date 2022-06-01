#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e9 + 5, M = 1e3 + 5, MOD = 32768, HV = 151, INF = 0x3f3f3f3f;
map<int, ll> dp;

ll solve(ll c)
{
    if (dp.find(c) == dp.end())
    {
        dp.insert({c, max(c, solve(c / 2) + solve(c / 3) + solve(c / 4))});
    }
    return dp[c];
}

void run()
{
    int n;
    while (~scanf("%d", &n))
    {
        dp.insert({0, 0});
        printf("%lld\n", solve(n));
        dp.clear();
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
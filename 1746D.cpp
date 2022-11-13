#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 30, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

vector<int> tre[N];
map<int, ll> dp[N];
int arr[N];

ll solve(int n, int k)
{
    if (dp[n].find(k) != dp[n].end())
    {
        return dp[n][k];
    }
    ll ret = 1ll * arr[n] * k;
    if (!tre[n].empty())
    {
        int m = tre[n].size(), d = k / m, r = k % m;
        for (auto &&i : tre[n])
        {
            ret += solve(i, d);
        }
        if (r)
        {
            vector<ll> res;
            for (auto &&i : tre[n])
            {
                res.push_back(solve(i, d + 1) - solve(i, d));
            }
            sort(res.begin(), res.end(), greater<ll>());
            for (int i = 0; i < r; i++)
            {
                ret += res[i];
            }
        }
    }
    return dp[n][k] = ret;
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 2, v; i <= n; i++)
    {
        scanf("%d", &v);
        tre[v].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    printf("%lld\n", solve(1, k));
    for (int i = 1; i <= n; i++)
    {
        tre[i].clear();
        dp[i].clear();
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 10, M = 8, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int dp[N], pos[N];

void run()
{
    int n;
    scanf("%d", &n);
    vector<int> act;
    for (int i = 1, y, s; i <= n; i++)
    {
        scanf("%d%d%d", &pos[i], &y, &s);
        int j = lower_bound(pos, pos + i, y) - pos;
        dp[i] = (((dp[i - 1] - dp[j - 1] + MOD) % MOD + pos[i] - y) % MOD + dp[i - 1]) % MOD;
        if (s)
        {
            act.push_back(i);
        }
    }
    int ans = 0;
    for (auto &&i : act)
    {
        ans = (ans + (dp[i] - dp[i - 1] + MOD) % MOD) % MOD;
    }
    printf("%d\n", (ans + pos[n] + 1) % MOD);
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
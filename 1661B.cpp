#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 5, MOD = 32768, HV = 151, INF = 0x3f3f3f3f;
int dp[MOD + 1];

void work(int v, int d)
{
    if (dp[v] < d || d > 15)
    {
        return;
    }
    dp[v] = d;
    work((v - 1 + MOD) % MOD, d + 1);
    if (v % 2 == 0)
    {
        work((v + MOD) / 2 % MOD, d + 1);
        work(v / 2 % MOD, d + 1);
    }
}

void run()
{
    memset(dp, 0x3f, sizeof(dp));
    dp[MOD] = dp[0] = 0;
    work(0, 0);
    // for (int i = 1; i <= MOD; i++)
    // {
    //     if (dp[i] == INF)
    //     {
    //         cout << i << endl;
    //     }
    // }
    int n;
    scanf("%d", &n);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        printf("%d\n", dp[v]);
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
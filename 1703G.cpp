#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 64, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll arr[N];
ll dp[N][M];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
    }
    memset((ll *)(dp + n), 0, sizeof(dp[0]));
    for (int i = n - 1; ~i; i--)
    {
        for (int j = 0; j < M - 1; j++)
        {
            dp[i][j] = max((arr[i] >> j) + dp[i + 1][j] - k, (arr[i] >> (j + 1)) + dp[i + 1][j + 1]);
        }
    }
    printf("%lld\n", dp[0][0]);
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
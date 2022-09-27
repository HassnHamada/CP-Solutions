#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e3 + 10, M = 1 << 13, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], dp[N][M];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dp[i][j] = min(dp[i - 1][0] + (j == arr[i] ? 0 : 1),
                           dp[i - 1][arr[i] ^ j] + 1);
        }
    }
    printf("%d\n", dp[n][0]);
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_ok.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
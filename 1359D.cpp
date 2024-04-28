#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 61, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int ans = 0;
    vector<int> dp(M, 0);
    for (int i = n - 1; ~i; --i)
    {
        for (int j = arr[i] + M / 2; j < M; j++)
        {
            dp[j] = max(dp[j] + arr[i], arr[i]);
            ans = max(ans, dp[j] - j + M / 2);
        }
    }
    printf("%d\n", ans);
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
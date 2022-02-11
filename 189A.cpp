#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;

const int N = 3, M = 4e3 + 10, MIN = -5e3;
int arr[N], dp[M];

void runDp(int n)
{
    int ret = MIN;
    for (int i = 0; i < N; i++)
    {
        if (n >= arr[i])
        {
            assert(dp[n - arr[i]] != -1);
            ret = max(ret, dp[n - arr[i]] + 1);
        }
    }
    dp[n] = ret;
}

void run()
{
    int n;
    cin >> n;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        runDp(i);
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << i << " " << dp[i] << endl;
    // }
    cout << dp[n] << endl;
}

int main(int argc, char const *argv[])
{
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}
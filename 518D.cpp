#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 2e3 + 10;
double dp[N][N];

void run()
{
    int n, t;
    double p;
    cin >> n >> p >> t;
    dp[0][1] = 1;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j] * (1 - p) + dp[i - 1][j - 1] * p;
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    // cout << endl;
    double ans = 0.0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp[t][i];
    }
    ans = n * (1 - ans);
    // cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        ans += (i - 1) * dp[t][i];
        // ans += i * (1 - dp[t][i]);
    }

    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10) << fixed;
    int test = 1;
    // cin >> t;
    while (test--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
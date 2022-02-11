// #include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;
// typedef long long int ll;
// #include <chrono>
// using namespace std::chrono;

const int N = 1e6 + 10;
int dp[N];

int calc(int n)
{
    assert(n);
    if (~dp[n])
    {
        return dp[n];
    }
    int ret = 0;
    for (int i = 1; i < n / 2; i++)
    {
        ret |= dp[i] ^ dp[n - i];
    }
    return ret;
}

void run()
{
    int n;
    cin >> n;
    dp[0] = dp[1] = 0;
    for (int i = 2; i < N; i++)
    {
        dp[i] = calc(i)?0:1;
        cout << i << " " << dp[i] << endl;
    }

    // cout << endl;
    // cout << (n > N || dp[n] ? "first" : "second") << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\_input.txt", "r", stdin);
    freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(6) << fixed;
    memset(dp, -1, sizeof(dp));
    int t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e2 + 10;
int bit[N], val[N];
ll dp[N][N][N];

ll solve(int s, int e, int r)
{
    // if (e - s < 0)
    // {
    //     return 0;
    // }
    if (s >= e)
    {
        return 0;
    }
    if (e - s == 1)
    {
        // cout << val[r] << endl;
        return val[r];
    }
    ll &ret = dp[s][e][r];
    if (~ret)
    {
        return ret;
    }
    ret = val[r] + solve(s + 1, e, 1);
    for (int i = s + 1; i < e; i++)
    {
        if (bit[s] == bit[i])
        {
            // cout << solve(s + 1, i, 1) + solve(i, e, r + 1) << endl;
            ret = max(ret, solve(s + 1, i, 1) + solve(i, e, r + 1));
        }
    }
    return ret;
}

void run()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        bit[i] = (c == '1');
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n, 1) << endl;
}
int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
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

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
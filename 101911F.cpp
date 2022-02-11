#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e6, M = 30;
int dp[N][M];

int unlucky(int n)
{
    int ret = 0;
    for (int i = 0; i < 3; i++)
    {
        ret -= n % 10;
        n /= 10;
    }
    for (int i = 0; i < 3; i++)
    {
        ret += n % 10;
        n /= 10;
    }
    // cout << n << " " << ret << endl;
    assert(n == 0 && ret >= -27 && ret <= 27);
    return abs(ret);
}

void run()
{
    int n;
    cin >> n;
    int m = unlucky(n), ans = 0;
    // cout << m << " ";
    for (int i = 0; i < m; i++)
    {
        ans += dp[n][i];
        // cout << i << " " << dp[n][i] << endl;
    }
    cout << ans << endl;
}

void pre()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
        dp[i][unlucky(i)]++;
    }
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
    pre();
    int test = 1;
    cin >> test;
    while (test--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
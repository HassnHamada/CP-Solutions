#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 120;
int dp[3][N];

int calc(int n)
{
    n = max(n, 0);
    return min({dp[0][n], dp[1][n], dp[2][n]});
}

void run()
{
    ll n;
    cin >> n;
    cout << n / N * 300 + (n % N > 4 || n < N ? calc(n % N) : (n % N > 2 ? 10 : (n % N ? 5 : 0))) << endl;
}

void pre()
{
    for (int i = 1; i < N; i++)
    {
        // int m = min({calc(i - 6), calc(i - 10), calc(i - 12)});
        dp[0][i] = min({calc(i - 6), calc(i - 6), calc(i - 6)}) + 15;
        dp[1][i] = min({calc(i - 8), calc(i - 8), calc(i - 8)}) + 20;
        dp[2][i] = min({calc(i - 10), calc(i - 10), calc(i - 10)}) + 25;
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    pre();
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

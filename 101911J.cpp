#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

// const int N = 2e3 + 10;
// double dp[N][N];

void run()
{
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll g = __gcd(x, y);
    x /= g;
    y /= g;
    // int a = x2 - x1 + 1, b = n - a, c = y1 - 1, d = m - y2;
    // cout << a << " " << b << " " << c << " " << d << endl;
    cout << min(a / x, b / y) << endl;
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
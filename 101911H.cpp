#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

// const int N = 2e3 + 10;
// double dp[N][N];

void run()
{
    int n, m, x1, x2, y1, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    int a = x2 - x1 + 1, b = n - a, c = y1 - 1, d = m - y2;
    // cout << a << " " << b << " " << c << " " << d << endl;
    cout << ((m & 1) * b + ((c & 1) + (d & 1)) * a + 1) / 2 << endl;
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
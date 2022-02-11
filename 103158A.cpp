#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

void run()
{
    // O(log(n))
    // int n, l = 1, h = INT32_MAX;
    // while (l < h)
    // {
    //     int m = l + (h - l + 1) / 2;
    //     if (1ll * m * (m + 1) / 2 <= n)
    //     {
    //         l = m;
    //     }
    //     else
    //     {
    //         h = m - 1;
    //     }
    // }
    // cout << n - l << endl;

    // O(1)
    int n;
    cin >> n;
    cout << n - (int)floor((-1 + sqrt(1 + 8ll * n)) / 2) << endl;
}
int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("alimagde.in", "r", stdin);
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
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
#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    double x1, y1, x2, y2, v, t, vx, vy, wx, wy;
    cin >> x1 >> y1 >> x2 >> y2 >> v >> t >> vx >> vy >> wx >> wy;
    double l = 0, h = 1e18;
    for (int i = 0; i < 100; i++)
    {
        double m = (h + l) / 2;
        double x = x1 + min(t, m) * vx + max(m - t, 0.0) * wx,
               y = y1 + min(t, m) * vy + max(m - t, 0.0) * wy;
        (hypot(x2 - x, y2 - y) > m * v ? l : h) = m;
    }
    cout << l << endl;

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
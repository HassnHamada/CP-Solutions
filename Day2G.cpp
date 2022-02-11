#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const double PI = 2 * acos(0);

void run()
{
    // cout << acos(-1.0) << endl;
    ll x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    assert(x1 * x1 + y1 * y1 + z1 * z1 == x2 * x2 + y2 * y2 + z2 * z2);
    double d = sqrt(x1 * x1 + y1 * y1 + z1 * z1),
           tha = acos(1.0 * (x1 * x2 + y1 * y2 + z1 * z2) / d / d);
    cout << tha * d << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10) << fixed;
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

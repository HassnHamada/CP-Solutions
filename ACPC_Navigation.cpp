#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(3) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        double r, lng1, lat1, lng2, lat2, PI = asin(1) * 2;
        cin >> r >> lng1 >> lat1 >> lng2 >> lat2;
        lng1 *= PI / 180;
        lat1 *= PI / 180;
        lng2 *= PI / 180;
        lat2 *= PI / 180;
        double x1 = r * cos(lat1) * cos(lng1),
               y1 = r * cos(lat1) * sin(lng1),
               z1 = r * sin(lat1);
        double x2 = r * cos(lat2) * cos(lng2),
               y2 = r * cos(lat2) * sin(lng2),
               z2 = r * sin(lat2);
        double l1 = sqrt(x1 * x1 + y1 * y1 + z1 * z1),
               l2 = sqrt(x2 * x2 + y2 * y2 + z2 * z2);
        double an = acos((x1 * x2 + y1 * y2 + z1 * z2) / l1 / l1);
        cout << (an == an ? l1 * an : 0) << endl;
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

// a*(1-c) + a*c*d
// a*(1-c-x/2) + a*(c+x/2)*d
// a*(1-c) + a*c*(d+x)
// d-1 > 2*c


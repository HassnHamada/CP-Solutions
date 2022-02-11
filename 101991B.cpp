#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const double ERR = 1e-12;

void run()
{
    double n;
    cin >> n;
    double ang = 4 * acos(0) / n, ans = 0;
    double s = sqrt(4.0 * tan(ang / 2) / n);
    for (int i = 1;; i++)
    {
        double area = n * (s * ((s / 2) / tan(ang / 2)) / 2.0);
        if (area < ERR)
        {
            break;
        }
        ans += area;
        s = 2 * ((s / 2) / tan(ang / 2)) * sin(ang / 2);
    }
    cout << ans * 1e4 << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen("baklava.in", "r", stdin);
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(5) << fixed;
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
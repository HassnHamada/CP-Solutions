#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

void run()
{
    int k;
    cin >> k;
    int l = 0, h = 4e4;
    while (l < h)
    {
        int m = l + (h - l) / 2;
        if (m * m < k)
        {
            l = m + 1;
        }
        else
        {
            h = m;
        }
    }
    int i = k - (l - 1) * (l - 1);
    int r = i / l ? l : i;
    int c = i / l ? l - i % l : l;
    cout << r << " " << c << endl;
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
#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

void run()
{
    int h, w, x1, y1, x2, y2, w0, h0, dw, dh;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2 >> w0 >> h0;
    if (w0 + x2 - x1 > w && h0 + y2 - y1 > h)
    {
        cout << "-1\n";
    }
    else
    {
        dw = max(x1, w - x2);
        dh = max(y1, h - y2);
        if (w0 + x2 - x1 <= w && h0 + y2 - y1 <= h)
        {
            cout << min(max(0, w0 - dw), max(0, h0 - dh)) << endl;
        }
        else
        {
            assert(w0 + x2 - x1 <= w || h0 + y2 - y1 <= h);
            cout << (w0 + x2 - x1 <= w ? max(0, w0 - dw) : max(0, h0 - dh)) << endl;
        }
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

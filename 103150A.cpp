#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

void run()
{
    int n, _;
    cin >> n >> _;
    int mn = INT32_MAX, mx = INT32_MIN;
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        mx = max(v, mx);
        mn = min(v, mn);
    }
    cout << mx - mn << endl;
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

//  1 0 0   0 1 0   0 0 1
//  0 1 1   1 0 1   1 1 0
//  2 1 1   1 2 1   1 1 2
//  2 3 3   3 2 3   3 3 2
//  6 5 5   5 6 5   5 5 6

#include <bits/stdc++.h>
// #include <chrono>
// #include "./stdc++.h"
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &&i : vec)
    {
        cin >> i;
    }
    int cMin = vec[0], iMin = 0;
    for (int i = 1; i < n; i++)
    {
        if (vec[i] <= cMin)
        {
            cMin = vec[i];
            iMin = i;
        }
    }
    int cMax = vec[n - 1], iMax = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (vec[i] >= cMax)
        {
            cMax = vec[i];
            iMax = i;
        }
    }
    cout << n - iMin - 1 + iMax - (iMax > iMin ? 1 : 0) << endl;
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}
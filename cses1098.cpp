#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;
// #include <chrono>
// using namespace std::chrono;

// const int N = 20;
// int arr[N], n, k;

void run()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        v %= 4;
        ans ^= v;
    }
    cout << (ans == 0 ? "second" : "first") << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(6) << fixed;
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
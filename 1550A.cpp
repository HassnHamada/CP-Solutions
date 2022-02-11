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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(3) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << ceil(sqrt(n)) << endl;
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

// sum 1 + 2 + 3 + 4 -> n = s
// sum 0 + 1 + 2 + 3 -> n = s

// sum 1 + 3 + 5 + 7 -> n = s
// n * n + n + n * n - n - n + 1 + n - 1 - 2 * s= 0
// 2 * n * n - 2 * s= 0
// a = 2, b = 0, c = -2 * s
// (-b + sqrt(b^2-4ac))/(2a)
// sqrt(s)

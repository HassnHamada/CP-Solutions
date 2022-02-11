#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e5 + 10;
pair<int, int> arr[N];

void run()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n);
    double ans = 0;
    for (int i = n - 2; ~i; i--)
    {
        if (arr[i].second > arr[i + 1].second)
        {
            double d = arr[i + 1].first - arr[i].first,
                   s = arr[i].second - arr[i + 1].second;
            // cout << d << " " << s << endl;
            ans = max(ans, d / s);
            arr[i] = arr[i + 1];
        }
    }
    cout << ans << endl;
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
    // cin >> t;
    while (t--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

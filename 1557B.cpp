#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e5 + 10;
int arr[N], srt[N];

void run()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        srt[i] = arr[i];
    }
    int c = 0;
    sort(srt, srt + n);
    for (int i = 0; i < n; c++)
    {
        int j = lower_bound(srt, srt + n, arr[i]) - srt;
        // cout << j << endl;
        while (i < n && j < n && srt[j] == arr[i] && ++i && ++j);
        // {
        //     cout << srt[j - 1] << " " << arr[i - 1] << endl;
        // }
        // cout << i << " " << j << endl;
    }
    // cout << c << endl;
    cout << (c <= k ? "Yes" : "No") << endl;
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

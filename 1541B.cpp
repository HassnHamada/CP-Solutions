#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e5 + 10;
pair<ll, ll> arr[N];

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i + 1;
        }
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n && arr[i].first * arr[j].first < 2ll * n; j++)
            {
                ans += (arr[i].first * arr[j].first == arr[i].second + arr[j].second);
            }
        }
        cout << ans << endl;
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

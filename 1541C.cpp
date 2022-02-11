#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 2e5 + 10;
ll arr[N], suf[N];

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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        sort(arr + 1, arr + n, greater<int>());
        suf[n - 1] = 0;
        for (int i = n - 2; i; i--)
        {
            suf[i] = suf[i + 1] + arr[i + 1];
        }
        ll ans = arr[1];
        for (ll i = 1; i < n; i++)
        {
            ans += suf[i] - (n - i) * arr[i];
        }
        cout << ans << endl;
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

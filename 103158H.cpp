#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e5 + 10;
ll arr[N];

void run()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    ll ans = INT64_MIN;
    for (int i = 1; i <= n; i++)
    {
        ll tem = INT64_MAX;
        for (int j = 0; j < n; j += i)
        {
            tem = min(tem, arr[min(j + i, n)] - arr[j]);
        }
        ans = max(ans, tem);
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen("bad-memes.in", "r", stdin);
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
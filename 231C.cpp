#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e5 + 10;
int arr[N];

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pair<int, int> ans = {1, arr[0]};
    sort(arr, arr + n);
    for (int i = 1, j = 0; i < n; i++)
    {
        k -= 1ll * (i - j) * (arr[i] - arr[i - 1]);
        while (k < 0)
        {
            k += arr[i] - arr[j++];
        }
        // cout << i << " " << j << " " << k << endl;
        // 6 3 4 0 2
        // 0 2 3 4 6
        if (i - j + 1 > ans.first)
        {
            ans.first = i - j + 1;
            ans.second = arr[i];
        }
    }
    cout << ans.first << " " << ans.second << endl;
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

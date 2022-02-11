#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10;
int arr[N];

bool ok(int s, int l)
{
    for (int i = s; i < s + l - 2; i++)
    {
        for (int j = i + 1; j < s + l - 1; j++)
        {
            for (int k = j + 1; k < s + l; k++)
            {
                int mx = max(arr[i], arr[k]), mn = min(arr[i], arr[k]);
                if (arr[j] >= mn && arr[j] <= mx)
                {
                    return false;
                }
            }
        }
    }
    return true;
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
        int ans = 2 * n - 1;
        for (int i = 3; i < 5; i++)
        {
            for (int j = 0; j <= n - i; j++)
            {
                ans += ok(j, i);
            }
        }
        cout << ans << endl;
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

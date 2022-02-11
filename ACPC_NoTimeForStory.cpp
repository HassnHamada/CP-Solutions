#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e5 + 10;
int arr[N], sz[N];

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
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
        for (int i = 0, j = -1, l = 0; i < n; i++)
        {
            cin >> arr[i];
            if (l != arr[i])
            {
                j += 1;
                l = arr[i];
                sz[j] = 0;
            }
            sz[j] += 1;
        }
        int m = unique(arr, arr + n) - arr, tem[3] = {0};
        for (int i = 0; i < m; i++)
        {
            tem[0] = sz[i];
            sort(tem, tem + 3);
        }
        int ans = tem[1] + tem[2];
        for (int i = 1; i < m - 1; i++)
        {
            if (arr[i - 1] != arr[i + 1])
            {
                continue;
            }
            ans = max(ans, sz[i - 1] + sz[i] + sz[i + 1]);
        }
        cout << ans << endl;
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

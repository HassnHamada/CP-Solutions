#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 2e5 + 10;
int arr[N], vis[N];

bool in(vector<int> vec, int num)
{
    auto it = lower_bound(vec.begin(), vec.end(), num);
    return it != vec.end() && *it == num;
}

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
        int mx = 0;
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            if (vis[arr[i]] == 2 * t + 1)
            {
                break;
            }
            mx = max(mx, arr[i]);
            if (mx == i + 1)
            {
                vec.push_back(i + 1);
            }
            vis[arr[i]] = 2 * t + 1;
        }
        mx = 0;
        vector<pair<int, int>> ans;
        for (int i = n - 1; i; i--)
        {
            if (vis[arr[i]] == 2 * t + 2)
            {
                break;
            }
            mx = max(mx, arr[i]);
            if (mx == n - i && in(vec, i))
            {
                ans.push_back({i, n - i});
            }
            vis[arr[i]] = 2 * t + 2;
        }
        cout << ans.size() << endl;
        for (auto &&i : ans)
        {
            cout << i.first << " " << i.second << endl;
        }
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

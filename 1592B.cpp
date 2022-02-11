#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10;
int arr[N], srt[N];
map<int, set<int>> ind;

void run()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        srt[i] = arr[i];
    }
    sort(srt, srt + n);
    for (int i = 0; i < n; i++)
    {
        ind[srt[i]].insert(i);
    }
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << arr[i] << endl;
        for (auto &&j : ind[arr[i]])
        {
            cout << j << " ";
            cout << (abs(i - j) >= x || abs(i % x - j) >= x) << endl;
        }
        cout << endl;
        ok &= any_of(ind[arr[i]].begin(), ind[arr[i]].end(), [&x, &i](int j)
                     { return abs(i - j) % x == 0; });
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\_input.txt", "r", stdin);
    freopen(".\\_output.txt", "w", stdout);
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

#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 2e5 + 10, K = 1e5 + 10;
ll arr[N];
queue<int> her[K];

void run()
{
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    her[0].push(0);
    pair<int, int> ans = {-1, 0};
    for (int i = 1; i <= n; i++)
    {
        int j = arr[i] % k;
        while (!her[j].empty() && arr[i] - arr[her[j].front()] > m)
        {
            her[j].pop();
        }
        if (!her[j].empty() && (i - her[j].front() > ans.second || (i - her[j].front() == ans.second && her[j].front() <= ans.first)))
        {
            ans = {her[j].front() + 1, i - her[j].front()};
        }
        her[j].push(i);
    }
    if (~ans.first)
    {
        cout << ans.first << " " << ans.second << endl;
    }
    else
    {
        cout << ans.first << endl;
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
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

#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

void run()
{
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        if (v)
        {
            pq.push({v, i + 1});
        }
    }
    vector<pair<int, int>> ans;
    while (pq.size() > 1)
    {
        pair<int, int> f = pq.top();
        pq.pop();
        pair<int, int> s = pq.top();
        pq.pop();
        ans.push_back({f.second, s.second});
        if (f.first - 1)
        {
            pq.push({f.first - 1, f.second});
        }
        if (s.first - 1)
        {
            pq.push({s.first - 1, s.second});
        }
    }
    cout << ans.size() << endl;
    for (auto &&i : ans)
    {
        cout << i.first << " " << i.second << endl;
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
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

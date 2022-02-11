#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 3e5 + 10;
int ans[N], arr[N], vis[N], vid;

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> arr[i];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0, v; i < k; i++)
        {
            cin >> v;
            pq.push({v, arr[i]});
        }
        vid += 1;
        while (!pq.empty())
        {
            pair<int, int> t = pq.top();
            pq.pop();
            if (t.second <= 0 || t.second > n || vis[t.second] == vid)
            {
                continue;
            }
            vis[t.second] = vid;
            ans[t.second] = t.first;
            pq.push({t.first + 1, t.second + 1});
            pq.push({t.first + 1, t.second - 1});
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " \n"[i == n];
        }
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}


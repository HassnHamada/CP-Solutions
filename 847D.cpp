#include <bits/stdc++.h>
// #include <chrono>
// #include "./stdc++.h"
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int> pq;
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1, v; i <= min(n, m); i++)
    {
        while (!pq.empty() && pq.top() >= m - i)
        {
            pq.pop();
        }
        cin >> v;
        if (max(v, i) < m)
        {
            pq.push(v - i);
        }
        ans = max(ans, (int)(pq.size()));
    }
    cout << ans << endl;
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
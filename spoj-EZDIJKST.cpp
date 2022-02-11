#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e4 + 10;
int ind[N], vis[N], vid;
vector<pair<int, int>> grf[N];

int Dijkstra(int a, int b)
{
    vid++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, a});
    while (!pq.empty())
    {
        pair<int, int> t = pq.top();
        pq.pop();
        if (vis[t.second] == vid)
        {
            continue;
        }
        if (t.second == b)
        {
            return t.first;
        }
        vis[t.second] = vid;
        for (int j = 0; j < ind[t.second]; j++)
        {
            pq.push({t.first + grf[t.second][j].second, grf[t.second][j].first});
        }
    }
    return -1;
}

void insert(int a, int b, int c)
{
    assert(ind[a] <= grf[a].size());
    if (ind[a] == grf[a].size())
    {
        grf[a].resize(2 * max((int)(grf[a].size()), 1));
    }
    grf[a][ind[a]++] = {b, c};
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
        int v, e;
        cin >> v >> e;
        for (int i = 0, a, b, c; i < e; i++)
        {
            cin >> a >> b >> c;
            insert(a, b, c);
        }
        int a, b;
        cin >> a >> b;
        int ret = Dijkstra(a, b);
        if (ret == -1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << ret << endl;
        }
        memset(ind, 0, v * sizeof(ind[0]));
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

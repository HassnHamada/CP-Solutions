#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e5 + 10;
int val[N];
bool out[N], vis[N];
vector<int> grf[N];

void dfs(int c)
{
    vis[c] = true;
    for (auto &&i : grf[c])
    {
        if (vis[i])
        {
            continue;
        }
        dfs(i);
    }
}

void run()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        grf[u].push_back(v);
        grf[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> out[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    int start;
    cin >> start;
    dfs(start);
    ll ans = 0;
    bool ok = false;
    for (int i = 1; i <= n; i++)
    {
        ans += vis[i] * val[i];
        ok |= vis[i] && out[i];
    }
    cout << (ok ? ans : -1ll) << endl;
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

// 1 1
// 1 2
// 1 3
// 1 4
// 2 2
// 2 3
// 2 4
// 3 3
// 3 4
// 4 4


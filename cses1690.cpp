#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;
// #include <chrono>
// using namespace std::chrono;

const int N = 20, MOD = 1e9 + 7;
int n, dp[N][1 << N];

struct Adj
{
    int head[N], to[N * N], nxt[N * N], sz, ne;
    void init(int _sz)
    {
        this->sz = _sz;
        memset(head, -1, _sz * sizeof(head[0]));
        ne = 0;
    }
    void addEdge(int f, int t)
    {
        nxt[ne] = head[f];
        to[ne] = t;
        head[f] = ne++;
    }
    void addBiEdge(int f, int t)
    {
        this->addEdge(f, t);
        this->addEdge(t, f);
    }
} grf;

int dfs(int c, int v)
{
    assert(c < n);
    v ^= (1 << c);
    if ((1 << n) - 1 == v && c == n - 1)
    {
        v ^= (1 << c);
        // cout << "dasd 1\n";
        return 1;
    }
    assert((1 << n) - 1 != v);
    if (c == n - 1)
    {
        v ^= (1 << c);
        // cout << "dasd 2\n";
        return 0;
    }
    if (~dp[c][v])
    {
        // cout << dp[c][v] << endl;
        // cout << "dasd 3\n";
        return dp[c][v];
    }
    // cout << c << " " << v << endl;
    int ret = 0;
    for (int i = grf.head[c]; ~i; i = grf.nxt[i])
    {
        if (v & (1 << grf.to[i]))
        {
            continue;
        }
        // cout << c << " " << i << " " << grf.to[i] << endl;
        ret = (0ll + ret + dfs(grf.to[i], v)) % MOD;
    }
    // cout << ret << endl;
    assert(ret >= 0);
    dp[c][v] = ret;
    v ^= (1 << c);
    // assert(dp[c][v] != -1);
    // cout << "dasd 4\n";
    return ret;
}

void run()
{
    int m;
    cin >> n >> m;
    grf.init(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0, f, t; i < m; i++)
    {
        cin >> f >> t;
        grf.addEdge(f - 1, t - 1);
    }
    cout << dfs(0, 0) << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(6) << fixed;
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
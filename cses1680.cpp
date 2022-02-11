#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10;
vector<int> grf[N];
int n, m, pre[N], dp[N];

void dfs(int c)
{
    int val = -2;
    for (auto &&i : grf[c])
    {

        if (dp[i] == -1)
        {
            dfs(i);
        }
        if (dp[i] == -2)
        {
            continue;
        }
        val = max(val, dp[i]);
    }
    if (val >= 0)
    {
        dp[c] = val + 1;
    }
    else
    {
        assert(val == -2);
        dp[c] = val;
    }
}

int next(int c, int d)
{
    for (auto &&i : grf[c])
    {
        if (dp[i] == d)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        grf[a].push_back(b);
    }
    memset(dp, -1, sizeof(dp));
    dp[n] = 0;
    dfs(1);
    if (dp[1] == -2)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << dp[1] + 1 << endl;
        for (int i = 1; ~i; i = next(i, dp[i] - 1))
        {
            cout << i << (i != n ? ' ' : '\n');
        }
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

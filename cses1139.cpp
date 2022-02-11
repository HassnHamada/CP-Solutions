#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;

const int N = 2e5 + 10;
int col[N], ans[N];
vector<int> tre[N];
set<int> sss[N];

int dfs(int n, int p)
{
    vector<int> res;
    for (auto &&i : tre[n])
    {
        if (i == p)
        {
            continue;
        }
        res.push_back(dfs(i, n));
    }
    int ret = n;
    for (auto &&i : res)
    {
        ret = sss[i].size() > sss[ret].size() ? i : ret;
    }
    sss[ret].insert(col[n]);
    for (auto &&i : res)
    {
        if (i == ret)
        {
            continue;
        }
        for (auto &&j : sss[i])
        {
            sss[ret].insert(j);
        }
    }
    ans[n] = sss[ret].size();
    return ret;
}

void run()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    // for (int i = 1, v; i <= n; i++)
    {
        cin >> col[i];
        // cin >> v;
        // ans[i].insert(v);
    }
    for (int i = 0, a, b; i < n - 1; i++)
    {
        cin >> a >> b;
        tre[a].push_back(b);
        tre[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }
}

int main(int argc, char const *argv[])
{
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
    return 0;
}
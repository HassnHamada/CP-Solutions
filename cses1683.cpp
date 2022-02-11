#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;

const int N = 1e5 + 10;
int n, m, cyc[N], cycId;
vector<int> grf[N];
bool vis[N], stk[N];
map<int, int> ans;

struct DSU
{
    int per[N];
    void init(int sz)
    {
        iota(per, per + sz, 0);
    }
    void merge(int a, int b)
    {
        per[this->get(b)] = per[this->get(a)];
    }
    int get(int a)
    {
        return this->per[a] == a ? a : this->get(per[a]);
    }
} dsu;

bool dfs(int c)
{
    cyc[c] = ++cycId;
    vis[c] = stk[c] = true;
    bool ret = false;
    for (int j = 0; j < grf[c].size(); j++)
    {
        int i = grf[c][j];
        i = dsu.get(i);
        if (vis[i])
        {
            if (stk[i] && dsu.get(i) != dsu.get(c))
            {
                dsu.merge(i, c);
                grf[i].insert(grf[i].end(), grf[c].begin(), grf[c].end());
                ret = true;
                break;
            }
            continue;
        }
        if (dfs(i) && cyc[c] != cyc[dsu.get(i)])
        {
            grf[dsu.get(i)].insert(grf[dsu.get(i)].end(), grf[c].begin(), grf[c].end());
            dsu.merge(i, c);
            ret = true;
            break;
        }
    }
    stk[c] = false;
    return ret;
}

void run()
{
    cin >> n >> m;
    dsu.init(n + 1);
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        grf[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        dfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans.find(cyc[dsu.get(i)]) == ans.end())
        {
            ans.emplace(cyc[dsu.get(i)], ans.size() + 1);
        }
    }
    cout << ans.size() << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << ans[cyc[dsu.get(i)]] << " \n"[i == n];
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
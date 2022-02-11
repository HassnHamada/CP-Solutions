#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;

const int N = 1e5 + 10, EMP = -1;
int n, m;
bool vis[N];
set<int> grf[N];
vector<int> ans;

void getInp()
{
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        grf[a].insert(b);
        grf[b].insert(a);
    }
}

int con(int c)
{
    vis[c] = true;
    int ret = grf[c].size();
    for (auto &&i : grf[c])
    {
        if (!vis[i])
        {
            ret += con(i);
        }
    }
    return ret;
}

bool ok()
{
    bool ret = true;
    for (int i = 1; i <= n; i++)
    {
        if (grf[i].size() % 2)
        {
            ret = false;
        }
    }
    // vector<bool> vis(n + 1, false);
    int res = con(1);
    return ret && res % 2 == 0 && res / 2 == m;
}

bool dfs(int c)
{
    ans.push_back(c);
    // if (c == 1)
    // {
    //     return m == 0;
    // }
    if (m == 0)
    {
        if (c == 1)
        {
            return true;
        }
        ans.pop_back();
        return false;
    }
    set<int> tem(grf[c].begin(), grf[c].end());
    for (int i : tem)
    {
        grf[c].erase(i);
        // grf[i].erase(c);
        m--;
        if (dfs(i))
        {
            return true;
        }
        // grf[c].insert(i);
        // grf[i].insert(c);
        // m++;
    }
    ans.pop_back();
    return false;
}

void run()
{
    getInp();
    if (ok())
    {
        memset(vis, 0, sizeof(vis));
        assert(dfs(1));
        for (auto &&i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE\n";
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
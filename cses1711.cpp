#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e2 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N];
vector<vector<int>> ans;

int deg[N];
bool in[N];

bool dfs(int n, int t)
{
    // cout << "in " << n << endl;
    // for (auto &&i : grf[n])
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    ans.back().push_back(n);
    if (n == t)
    {
        // cout << "out " << n << endl;
        return true;
    }
    in[n] = true;
    while (!grf[n].empty())
    {
        int v = grf[n].back();
        grf[n].pop_back();
        if (!in[v])
        {
            if (dfs(v, t))
            {
                // cout << "out " << n << endl;
                in[n] = false;
                return true;
            }
        }
    }
    in[n] = false;
    // cout << "out " << n << endl;
    ans.back().pop_back();
    return false;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u].push_back(v);
        deg[u]--;
        deg[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(grf[n].begin(), grf[n].end(), [](int j, int k)
             { return deg[j] < deg[k]; });
        // for (auto &&j : grf[i])
        // {
        //     cout << j << " ";
        // }
        // cout << endl;
    }
    while (!grf[1].empty())
    {
        ans.emplace_back();
        if (!dfs(1, n))
        {
            ans.pop_back();
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto &&i : ans)
    {
        printf("%d\n", (int)i.size());
        for (auto &&j : i)
        {
            printf("%d%c", j, " \n"[j == n]);
        }
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
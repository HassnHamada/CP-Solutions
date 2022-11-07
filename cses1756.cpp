#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

bool vis[N], in[N];
vector<int> grf[N];

void dfs(int n, int p = 0)
{
    // cout << "in " << n << endl;
    vis[n] = in[n] = true;
    int m = grf[n].size();
    for (int k = 0; k < m; k++)
    {
        int i = grf[n][k], j = k + 1 < m ? grf[n][k + 1] : -1;
        if (i == p)
        {
            continue;
        }
        if (in[i])
        {
            printf("%d %d\n", i, n);
        }
        else if (!vis[i])
        {
            printf("%d %d\n", n, i);
        }
        if (vis[i] || i == j)
        {
            continue;
        }
        dfs(i, n);
    }
    in[n] = false;
    // cout << "out " << n << endl;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u].push_back(v);
        grf[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(grf[i].begin(), grf[i].end());
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i);
    }
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
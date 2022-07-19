#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 26, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N];
int col[N], frq[N];
bool vis[N];

bool dfs(int n, int p = 0)
{
    // cout << "in " << n << " " << p << endl;
    assert(grf[n].size() <= 2);
    vis[n] = true;
    col[n] = p;
    for (auto &&i : grf[n])
    {
        if (vis[i])
        {
            if (col[i] == p)
            {
                // cout << "out A " << n << " " << p << endl;
                return false;
            }
            continue;
        }
        if (!dfs(i, p ^ 1))
        {
            // cout << "out B " << n << " " << p << endl;
            return false;
        }
    }
    // cout << "out C " << n << " " << p << endl;
    return true;
}

void run()
{
    int n;
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis[0]) * (n + 1));
    memset(frq, 0, sizeof(frq[0]) * (n + 1));
    for (int i = 0, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        frq[u] += 1;
        frq[v] += 1;
        grf[u].push_back(v);
        grf[v].push_back(u);
    }
    bool ok = true;
    for (int i = 1; ok && i <= n; i++)
    {
        ok = frq[i] == 2;
    }
    for (int i = 1; ok && i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        ok = dfs(i);
    }
    printf(ok ? "YES\n" : "NO\n");
    for (int i = 1; i <= n; i++)
    {
        grf[i].clear();
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}

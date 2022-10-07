#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e2 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int prv[N], cap[N][N];

vector<int> grf[N];

bool bfs(int s, int e)
{
    memset(prv, -1, sizeof(prv));
    queue<int> q;
    q.emplace(s);
    while (!q.empty())
    {
        auto n = q.front();
        q.pop();
        for (auto &&i : grf[n])
        {
            if (i != s && prv[i] == -1 && cap[n][i])
            {
                prv[i] = n;
                if (i == e)
                {
                    return true;
                }
                q.push(i);
            }
        }
    }
    return false;
}

bool vis[N];

void dfs(int n, vector<int> &out)
{
    vis[n] = true;
    out.push_back(n);
    for (auto &&i : grf[n])
    {
        if (!vis[i] && cap[n][i])
        {
            dfs(i, out);
        }
    }
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1, a, b; i <= m; i++)
    {
        scanf("%d%d", &a, &b);
        grf[a].push_back(b);
        grf[b].push_back(a);
        cap[a][b] = cap[b][a] = 1;
    }
    while (bfs(1, n))
    {
        int c = n;
        while (c != 1)
        {
            cap[prv[c]][c] -= 1;
            cap[c][prv[c]] += 1;
            c = prv[c];
        }
    }
    vector<int> out;
    dfs(1, out);
    vector<pair<int, int>> ans;
    for (auto &&i : out)
    {
        for (auto &&j : grf[i])
        {
            if (!vis[j])
            {
                assert(cap[i][j] == 0);
                ans.emplace_back(i, j);
            }
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto &&[a, b] : ans)
    {
        printf("%d %d\n", a, b);
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
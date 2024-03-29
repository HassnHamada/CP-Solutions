#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e2 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N];
int prv[N], cap[N][N];

bool bfs(int s, int e)
{
    memset(prv, -1, sizeof(prv));
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        for (auto &&j : grf[n])
        {
            int i = abs(j);
            if (i != s && prv[i] == -1 && cap[n][i])
            {
                prv[i] = n;
                q.push(i);
                if (i == e)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool vis[N];

void dfs(int n, int s, int e, vector<vector<int>> &ans)
{
    if (n == e)
    {
        ans.back().push_back(n);
        return;
    }
    vis[n] = true;
    for (auto &&i : grf[n])
    {
        if (i < 0 || cap[n][i] || vis[i])
        {
            continue;
        }
        if (n == s)
        {
            ans.emplace_back();
        }
        ans.back().push_back(n);
        dfs(i, s, e, ans);
        i *= -1;
        if (n != s)
        {
            break;
        }
    }
    vis[n] = false;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u].push_back(v);
        grf[v].push_back(-u);
        cap[u][v] = 1;
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
    vector<vector<int>> ans;
    dfs(1, 1, n, ans);
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
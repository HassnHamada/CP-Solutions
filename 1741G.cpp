#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 10, M = 6, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N], rid[N];
int frd[N], no_car[M], inq[N], qid;
bool liv[N];
vector<int> dp[N][1 << M];
set<int> don[N];

int _car(int n, int k)
{
    for (int i = 0; i < k; i++)
    {
        if (no_car[i] - 1 == n)
        {
            return false;
        }
    }
    return true;
}

int _no_car(int n, int k)
{
    int ret = 0;
    for (int i = 0; i < k; i++)
    {
        if (frd[no_car[i] - 1] == n)
        {
            ret |= (1 << i);
        }
    }
    if (ret)
    {
        return ret;
    }
    return -1;
}

void solve(int c, int r, int f, int k)
{
    if (c == f)
    {
        dp[c][r].push_back(r);
    }
    if (dp[c][r].empty())
    {
        if (_car(c, k))
        {
            vector<int> &ret = dp[c][r];
            for (auto &&i : rid[frd[c]])
            {
                solve(c + 1, r | i, f, k);
                vector<int> &res = dp[c + 1][r | i];
                ret.insert(ret.end(), res.begin(), res.end());
                sort(ret.begin(), ret.end());
                ret.erase(unique(ret.begin(), ret.end()), ret.end());
            }
        }
        else
        {
            solve(c + 1, r, f, k);
            dp[c][r].insert(dp[c][r].begin(), dp[c + 1][r].begin(), dp[c + 1][r].end());
        }
    }
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
    int f;
    scanf("%d", &f);
    for (int i = 0; i < f; i++)
    {
        scanf("%d", frd + i);
        if (!liv[frd[i]])
        {
            rid[frd[i]].push_back(0);
            liv[frd[i]] = true;
        }
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", no_car + i);
    }
    queue<pair<int, int>> q;
    q.push({1, 0});
    inq[1] = ++qid;
    while (!q.empty())
    {
        queue<pair<int, int>> t;
        while (!q.empty())
        {
            auto [u, r] = q.front();
            q.pop();
            if (don[u].find(r) != don[u].end())
            {
                continue;
            }
            don[u].insert(r);
            for (auto &&v : grf[u])
            {
                if (inq[v] == qid)
                {
                    continue;
                }
                int res = _no_car(v, k);
                res = r | (~res ? res : 0);
                t.push({v, res});
                if (liv[v])
                {
                    rid[v].push_back(res);
                }
            }
        }
        while (!t.empty())
        {
            auto [u, r] = t.front();
            t.pop();
            inq[u] = qid;
            q.push({u, r});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(rid[i].begin(), rid[i].end());
        rid[i].erase(unique(rid[i].begin(), rid[i].end()), rid[i].end());
    }
    solve(0, 0, f, k);
    int ans = k;
    for (auto &&i : dp[0][0])
    {
        ans = min(ans, k - __builtin_popcount(i));
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
    {
        grf[i].clear();
        rid[i].clear();
        don[i].clear();
    }
    for (int i = 0; i <= f; i++)
    {
        for (int j = 0; j < (1 << M); j++)
        {
            dp[i][j].clear();
        }
    }
    memset(liv, 0, sizeof(liv[0]) * (n + 1));
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}

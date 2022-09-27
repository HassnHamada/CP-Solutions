#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N];
int ids[N], low[N], cyc[N], id, cid;
bool onStk[N];
stack<int> stk;

void dfs(int c)
{
    low[c] = ids[c] = id++;
    onStk[c] = true;
    stk.push(c);
    for (auto &&i : grf[c])
    {
        if (ids[i] == -1)
        {
            dfs(i);
        }
        if (onStk[i])
        {
            low[c] = min(low[c], low[i]);
        }
    }
    if (low[c] == ids[c])
    {
        cyc[c] = cid++;
        while (true)
        {
            int t = stk.top();
            stk.pop();
            onStk[t] = false;
            cyc[t] = cyc[c];
            low[t] = low[c];
            if (t == c)
            {
                break;
            }
        }
    }
}

bool ok(int n)
{
    memset(ids, -1, sizeof(ids[0]) * n << 1);
    for (int i = 0; i < (n << 1); i++)
    {
        if (ids[i] == -1)
        {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (cyc[i << 1] == cyc[(i << 1) + 1])
        {
            return false;
        }
    }
    return true;
}

int inp[N >> 1];
pair<int, int> swt[N >> 1];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", inp + i);
    }
    for (int i = 1, l; i <= m; i++)
    {
        scanf("%d", &l);
        for (int j = 0, v; j < l; j++)
        {
            scanf("%d", &v);
            (swt[v].first ? swt[v].second : swt[v].first) = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        assert(swt[i].first);
        assert(swt[i].second);
    }
    for (int i = 1; i <= n; i++)
    {
        int a0 = (swt[i].first - 1) << 1, a1 = a0 + 1, b0 = (swt[i].second - 1) << 1, b1 = b0 + 1;
        if (inp[i])
        {
            grf[a1].push_back(b1);
            grf[b0].push_back(a0);
            grf[a0].push_back(b0);
            grf[b1].push_back(a1);
        }
        else
        {
            grf[a0].push_back(b1);
            grf[b0].push_back(a1);
            grf[a1].push_back(b0);
            grf[b1].push_back(a0);
        }
    }
    printf(ok(m) ? "YES\n" : "NO\n");
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}